#include "es_util.h"
#include "tcp_server.h"

using namespace es;

int main(int argc, char **argv) {
    // accept 工作线程组
    EventWorkGroup boss(4);
    // socket 工作线程组
    EventWorkGroup worker(8);
    // 用户id
    atomic_int64_t userid(0);
    // 连接列表
    unordered_map<int64_t, TcpConnectionPtr> connectionPools;

    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%L%$] [tid %t] %v");
    TcpServerPtr ss = TcpServer::startServer(
        &boss, &worker,
        [&](const TcpConnectionPtr &con) {
            spdlog::info("Server accept: {}", con->fd());
            connectionPools[userid++] = con;
            con->onState([&](const TcpConnectionPtr &con) {
                if (con->state() == TcpConnection::TcpState::kClosed) {
                    // clear connectionPools;
                }
            });
            con->onFreeTimeOut(40 * 1000, [&](const TcpConnectionPtr &con) { con->close(); });
            con->onRead([&](const TcpConnectionPtr &con) {
                spdlog::info("Server onRead: {}, size{} ", con->fd(),con->getReadBuffer().size());
                con->getReadBuffer().consume(con->getReadBuffer().size());
            });
        },
        "127.0.0.1", 9950, true);
    assert(ss != nullptr);
    Signal::signal(SIGINT, [&] {
        boss.exit();
        worker.exit();
    });
    boss.sync();
    worker.sync();
}
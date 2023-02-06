#include <iostream>
#include <stdlib.h>
#include <stdio.h>
class myHandler : public Handler{
	virtual void handleMessage(Message& msg) override {
		Handler::handleMessage(msg);
		switch(msg.m_what){
		case 0:

			break;

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		default:
			break;
		}

		cout << "IN myHandler case: " << msg.m_what << endl;
	}
};

int main(int argc, char **argv)
{
	cout << "IN main" << endl;

	myHandler hdlr;
	for(int i = 0; i < 6; i++){
		hdlr.sendEmptyMessage(i, 100 * i);
	}

	hdlr.postAtTime([](){
		cout << "IN POST call back" << endl;
	}, 230);

	hdlr.stopSafty(true); //停止handler，在停止前處理完所有訊息
	while(true){
		std::this_thread::sleep_for(std::chrono::seconds(100000));
	}
	return 1;
}
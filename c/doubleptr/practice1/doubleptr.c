int main() {
    int p = 10;
    int *ptr = &p;

    int addr1 = (int)&p;     //addr1=2162196
    int addr2 = (int)ptr;    //addr2=2162196
    int addr3 = (int)&ptr;   //addr3=2162184

    printf("addr1 (&p)   = 0x%x \n", addr1);
    printf("addr2 (ptr)  = 0x%x \n", addr2);
    printf("addr3 (&ptr) = 0x%x \n", addr3);
    return 0;
}
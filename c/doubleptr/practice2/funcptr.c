int main() {
    int p = 10;
    int *ptr1 = &p;
    int **ptr2 = &ptr1;

    int addr1 = (int)&p;     //addr1=2291940
    int addr2 = (int)ptr1;   //addr2=2291940
    int addr3 = (int)&ptr1;  //addr3=2291928
    int val   = **ptr2;      //val=10
    int addr4 = (int)*ptr2;  //addr2=2291940
    int addr5 = (int)&ptr2;  //addr3=2291916

    printf("addr1 (&p)     = 0x%x \n", addr1);
    printf("addr2 (ptr1)   = 0x%x \n", addr2);
    printf("addr3 (&ptr1)  = 0x%x \n", addr3);
    printf("val   (**ptr2) = 0x%x \n", val);
    printf("addr4 (*ptr2)  = 0x%x \n", addr4);
    printf("addr5 (&ptr2)  = 0x%x \n", addr5);

    return 0;
}
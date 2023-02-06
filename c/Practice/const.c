int FindNum(const int array[], int num, int conut);//聲明函數

//code...

int FindNum(const int array[], int num, int count)
{
    int i;
    int flag = 1;

    for (i = 0; (i < count) && flag; i++)
    {
        if (array[i] == num)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
 //code...
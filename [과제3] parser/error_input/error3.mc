int LargeNum(int, int);
int Reverse();
int num1,num2;

int LargeNum(int num1, int num2)
{
    if(num1>)
    {
        return num1;
    }
    else
    {
        return ;
    }
}

int Reverse(int num1)
{
    int A1,A2,A3,A4;
    A1=num1%10; // 1의 자리
    A2=(num1/10)%10; // 10의 자리
    A3=(num1/100);; // 100의 자리
    A4=A1*100+A2*10+A3;
    return A4;
}

int main() {
    int a;
    int b;
    int result;

    scanf("%d %d",&a,&b);
    printf("%d", LargeNum(Reverse(a),Reverse(b)));
    return 0;


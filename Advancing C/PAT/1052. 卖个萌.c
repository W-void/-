//这道题不难，代码是copy的
/*
1052. 卖个萌 (20)

萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：
输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；
每个符号包含1到4个非空字符。
之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——
这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。
输出格式：
对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。

输入样例：
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/
#include<stdio.h>
#define MAX 12
char hand[MAX][30];
char eye[MAX][30];
char mouth[MAX][30]; 
int get(char p[][30]);
int main()
{
    int len1,len2,len3;
    len1=get(hand);
    len2=get(eye);
    len3=get(mouth);
    int n;
    int h1,h2,m,e1,e2;
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d%d",&h1,&e1,&m,&e2,&h2);
        if((h1>len1)|| (e1>len2) || (m>len3) || (e2>len2) || (h2>len1)) //选择的序号超出了上界
            printf("Are you kidding me? @\\/@");
        else if((h1<1) || (e1<1) || (m<1) || (e2<1) || (h2<1))//选择的序号超出了下界
            printf("Are you kidding me? @\\/@");
        else 
            printf("%s(%s%s%s)%s",hand[h1],eye[e1],mouth[m],eye[e2],hand[h2]);
        putchar('\n');
    }
    return 0;
}
int  get(char p[][30])
{
    int i=0,j=0, c;
    int count=0;
    int  flag=0;//是否进入[]的标志位
        while((c=getchar())!='\n')
        {
                if(c=='[')
                {       
                        flag =1;//已经进入“[”
                        i++;//保存下一个符号
                        j=0;
                        count++;
                }
                else if(c==']')
                {
                        flag = 0;//已经退出“]”
                        p[i][j]=0;
                }       
                else
                {
                        if(flag ==1)
                        p[i][j++]=c;//将[]内的字符保存进数组
                }
        }   
    return count;//返回字符集中符号个数
}

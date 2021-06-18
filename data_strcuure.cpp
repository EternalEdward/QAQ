#include <bits/stdc++.h>
using namespace std;
/*
   输入一页文字，
   程序可以统计出文字、数字、空格的个数；
   静态存储一页文章，每行最多不超过80个字符，共N行。
*/
typedef struct Node{//我讲将这个函数作为行
    char data[85];
    int length=0;
    int notblank=0;
    struct Node *next;
}Node,*LinkList;
void CreatText(LinkList &L){
    int QAQ=0;
    LinkList x,r;
    int n=1;//我的数据是从data[1]开始存储的
    cout<<"input your text:"<<endl;
    char ch;
    scanf("%d",&ch);
    x=(LinkList)malloc(sizeof(Node));
    n=800;
    r=L;//这里使用尾插法
    while(ch!='#'){//输入
        if(n>80||ch=='@'){
            if(ch=='@')
                scanf("%c",&ch);
            n=1;
            x=(LinkList)malloc(sizeof(Node));
            x->length=1;
            if(ch!=' '){
                x->notblank=1;
            }
            else{
                x->notblank=0;
            }
            x->data[n]=ch;
            r->next=x;
            r=x;
        }
        else{
            if(QAQ==0){
                r->next=x;
                r=x;
            }
            x->data[n]=ch;
            if(ch!=' ') { x->notblank++; }
            x->length++;        
        }
        QAQ=10000;
        n++;
        scanf("%c",&ch);
    }
    r->next=NULL;
    cout<<"input has enden"<<endl;
}

void tocount(LinkList x){// 统计出其中英文字母数和空格数及整篇文章总字数；
    int num_CE=0;
    int num_blank=0;
    int num_tol=0;
    ////待会要改，目前写的是只能针对一行的
    //已经完成修改
    while(x->next!=NULL){
        x=x->next;
        for(int i=1;i<=x->length;i++){
            if(x->data[i]==' '){
                num_blank++;
                }
            if((x->data[i]>='A'&&x->data[i]<='Z')||(x->data[i]>='a'&&x->data[i]<='z')){
                num_CE++;
            }
        }
        num_tol+=x->length;
    }
    num_tol=num_tol-num_blank;
    printf("word:%d\nblank:%d\ntotal:%d\n",num_CE,num_blank,num_tol);
}

void strcount(LinkList S){//统计某一字符串  在文章中出现的次数，并输出该次数
//我应该写完了吧
    LinkList x;
    char ch[20];
    x=S;    
    cout<<"input the string which you want to search"<<endl;
    cin>>ch;
    int n;
    int flagex=0;
    int flagey=0;
    int times=0;
    n=strlen(ch);
    while(x->next!=NULL){
        flagex=0;
        flagey=0;
        x=x->next;
        for(int i=1;i<=(x->length-n);i++){
            if(x->data[i]==ch[0])
                {
                    flagex=1;
                    for(int k=1;k<n;k++)
                    {
                        if(x->data[i+k]!=ch[k]){
                            break;
                            flagey=0;
                        }
                        flagey=1;
                    }
                }            
        }
        if(flagey==1)
            times++;
    }
    printf("this string has appered %d times\n",times);
}

void del(LinkList &S){//删除某一子串，并将后面的字符前移。
    LinkList x=S;
    cout<<"input the number of line about the string which you want to delete"<<endl;
    int line;
    cin>>line;
    cout<<"intput the string which you want to delete : "<<endl;
    char ch[10];
    cin>>ch;
    int n;
    int q;
    int flage=0;
    int target;
    n=strlen(ch);
    
    for(int i=1;i<=line;i++){
        x=x->next;
    }
    for(int j=1;j<x->length;j++){
        //进行判断
        if(x->data[j]==ch[0])
            for(q=1;q<=n;q++){
                if(x->data[j+q]!=ch[q]){
                    //flage=0;//标记不是目标到下一个去找
                    break;
                }                   
            }
            if(q==n){
                    flage=1 ;
                    target=j;
                } 
            for(int k=target;k<=x->length;k++){//进行删除
                x->data[k]=x->data[k+n];
            }
    }
    cout<<"deleted end"<<endl;
}



void output(LinkList L){//文本输出函数
    cout<<"star print text:"<<endl;
    while(L!=NULL){
        for(int i=1;i<=L->length;i++)
            cout<<L->data[i];
        cout<<endl;
        L=L->next;
    }
}

int f=1;
int mune(){
    int x;
    if(f){
    cout<<"\n\n\n\t|================================================MENU============================================|"<<endl;
    cout<<"\t|1) Input the message                                                                            |"<<endl;//文本输入
    cout<<"\t|2) Caculate the number of word and blank ,and count the totle number of the whole message's word|"<<endl;// 统计出其中英文字母数和空格数及整篇文章总字数；
    cout<<"\t|3) Caculate a string's appearing times and output it                                            |"<<endl;//统计某一字符串  在文章中出现的次数，并输出该次数；
    cout<<"\t|4) Delete a string                                                                              |"<<endl;//删除某一子串，并将后面的字符前移
    cout<<"\t|5) Output text                                                                                  |"<<endl;//打印文本
    cout<<"\t|6) Exit                                                                                         |"<<endl;
    cout<<"\t|================================================================================================|"<<endl;
    cout<<"Please input your option:\n"<<endl;
    }
    cin>>x;
    return x;
}

int main(){
    LinkList L;
    L=(LinkList)malloc(sizeof(Node));
    L->next=NULL;
    int n;
    while(1){
        switch(mune()){
            case 1:{
                f=1;
                cout<<"input '#' to end input "<<endl;
                CreatText(L);
                break;
                }

            case 2:{
                f=1;
                tocount(L);// 统计出其中英文字母数和空格数及整篇文章总字数
                break;
                }

            case 3:{
                f=1;
                strcount(L);//统计某一字符串  在文章中出现的次数，并输出该次数
                break;
                }

            case 4:{
                f=1;
                del(L);//删除某一子串，并将后面的字符前移。
                break;
                }

            case 5:{
                output(L);
                f=1;
                break;
                }
            case 6:{
                exit(1);
                }

            default:{
                cout<<"An illegal input ,please input once again:"<<endl;
                f=0;
                break;
                }
        }
    }
    return 0;
}

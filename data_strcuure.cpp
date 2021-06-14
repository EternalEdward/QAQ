#include <bits/stdc++.h>
using namespace std;
#define CH 80
/*
   输入一页文字，
   程序可以统计出文字、数字、空格的个数；
   静态存储一页文章，每行最多不超过80个字符，共N行。
*/
typedef struct Node{//我讲将这个函数作为行
    char line[80];
    struct Node *next;
    struct Node 
}Node,*LinkList;
void CreatText(LinkList &L){
    LinkList x,r;
    char QAQ[80];
    r=L;
    int n;
    cout<<"input the number of line:"<<endl;
    cin>>n;
    getchar();
    cin>>QAQ;
    while(QAQ[1]!='0'){
        x=(LinkList)malloc(sizeof(Node));
        x->line[n]=QAQ[n];
        r->next=x;
        r=x;
        cin>>QAQ;
    }
    r->next=NULL;
    cout<<"end"<<endl;
}
void tocount(Node S){//// 统计出其中英文字母数和空格数及整篇文章总字数；

}

void strcount(Node S){//统计某一字符串  在文章中出现的次数，并输出该次数；


}

void compare(Node S,string ch){//

}

void del(Node &S,string ch){//

}
int f=1;
int mune(){
    int x;
    if(f){
    cout<<"\n\n\n\t|================================================mune============================================|"<<endl;
    cout<<"\t|1) Input the message                                                                            |"<<endl;//cout<<"1) 文本输入"<<endl;
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
    int n;
    while(1){
        switch(mune()){
            case 1:{
                f=1;
                CreatText(L);
                break;
                }

            case 2:{
                f=1;
                break;
                }

            case 3:{
                f=1;

                break;

                }

            case 4:{
                f=1;
                break;
                }

            case 5:{
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

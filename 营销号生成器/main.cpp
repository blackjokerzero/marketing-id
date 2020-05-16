#include <iostream>
#include<cstdio>
#include<windows.h> 
#include<conio.h>
#include<set>
using namespace std;
void Set(int x,int y){
		HANDLE hOut;
		COORD pos={x,y};//定义位置 
		hOut=GetStdHandle(STD_OUTPUT_HANDLE);//获得句柄 
		SetConsoleCursorPosition(hOut,pos);//设置光标位置 
	
}
bool write(const char* data,const int len){
	
	if(OpenClipboard(NULL)){//打开剪贴板 
		EmptyClipboard();//清空剪贴板 
		HGLOBAL hclip=GlobalAlloc(GMEM_DDESHARE,len+1);//分配内存 
		char *buffer=(char *)GlobalLock(hclip);//锁定内存，防止其他程序更改 
		strcpy(buffer,data);//把我们的字符串复制进去 
		GlobalUnlock(hclip);//解锁内存 
		SetClipboardData(CF_TEXT,hclip);//设置剪贴板数据 
		CloseClipboard();//关闭 剪贴板 
		return true;
	}
	return false;
}
char s1[1000],s2[1000],s3[1000];//输入字符串 
char s[10000];//输出字符串 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"主体："<<endl;
	cout<<"事件："<<endl;
	cout<<"另一种说法："<<endl;
	Set(6,0);
	gets(s1);
	Set(6,1);
	gets(s2);
	Set(12,2);
	gets(s3);
	
	//格式化字符串 
		sprintf(s,"%s%s是怎么回事呢？%s相信大家都很熟悉，但是%s%s是怎么回事呢，下面就让小编带大家一起了解吧。\n%s%s，其实就是%s，大家可能会很惊讶%s怎么会%s呢？但事实就是这样，小编也感到非常惊讶。\n这就是关于%s%s的事情了，大家有什么想法呢，欢迎在评论区告诉小编一起讨论哦！",s1,s2,s1,s1,s2,s1,s2,s3,s1,s2,s1,s2);
		cout<<s<<endl;
		cout<<"按下回车键复制，按下其他键退出";
		if(getch()==13)
		{
			if(write(s,strlen(s))==true)
			cout<<"复制成功"<<endl;
			else
			cout<<"复制失败"<< endl;
			Sleep(3000);
		 } 
	return 0;
}

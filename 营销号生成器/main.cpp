#include <iostream>
#include<cstdio>
#include<windows.h> 
#include<conio.h>
#include<set>
using namespace std;
void Set(int x,int y){
		HANDLE hOut;
		COORD pos={x,y};//����λ�� 
		hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��þ�� 
		SetConsoleCursorPosition(hOut,pos);//���ù��λ�� 
	
}
bool write(const char* data,const int len){
	
	if(OpenClipboard(NULL)){//�򿪼����� 
		EmptyClipboard();//��ռ����� 
		HGLOBAL hclip=GlobalAlloc(GMEM_DDESHARE,len+1);//�����ڴ� 
		char *buffer=(char *)GlobalLock(hclip);//�����ڴ棬��ֹ����������� 
		strcpy(buffer,data);//�����ǵ��ַ������ƽ�ȥ 
		GlobalUnlock(hclip);//�����ڴ� 
		SetClipboardData(CF_TEXT,hclip);//���ü��������� 
		CloseClipboard();//�ر� ������ 
		return true;
	}
	return false;
}
char s1[1000],s2[1000],s3[1000];//�����ַ��� 
char s[10000];//����ַ��� 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"���壺"<<endl;
	cout<<"�¼���"<<endl;
	cout<<"��һ��˵����"<<endl;
	Set(6,0);
	gets(s1);
	Set(6,1);
	gets(s2);
	Set(12,2);
	gets(s3);
	
	//��ʽ���ַ��� 
		sprintf(s,"%s%s����ô�����أ�%s���Ŵ�Ҷ�����Ϥ������%s%s����ô�����أ��������С������һ���˽�ɡ�\n%s%s����ʵ����%s����ҿ��ܻ�ܾ���%s��ô��%s�أ�����ʵ����������С��Ҳ�е��ǳ����ȡ�\n����ǹ���%s%s�������ˣ������ʲô�뷨�أ���ӭ������������С��һ������Ŷ��",s1,s2,s1,s1,s2,s1,s2,s3,s1,s2,s1,s2);
		cout<<s<<endl;
		cout<<"���»س������ƣ������������˳�";
		if(getch()==13)
		{
			if(write(s,strlen(s))==true)
			cout<<"���Ƴɹ�"<<endl;
			else
			cout<<"����ʧ��"<< endl;
			Sleep(3000);
		 } 
	return 0;
}

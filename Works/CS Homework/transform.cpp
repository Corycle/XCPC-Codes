/*====Corycle====*/
#include<bits/stdc++.h>
#include"bmp.h"
using namespace std;
const int N=2505;
BMP bmp1,bmp2;
IMAGEDATA *bmpImg1,*bmpImg2;
FILE *FILE_INPUT,*FILE_OUTPUT;
int offset1,offset2,Height,Width;
int ID1(int x,int y){return x*bmp1.info.biWidth+y;}
int ID2(int x,int y){return x*bmp2.info.biWidth+y;}
void Close(int x){
	fclose(FILE_INPUT);
	fclose(FILE_OUTPUT);
	exit(x);
}
void Print_Error1(){
	cerr<<"Error!"<<endl;
	cerr<<"Your command should be with three parameter."<<endl;
	cerr<<"Usage: ./transform infile outfile mode"<<endl;
}
void Print_Error2(char *s){
	cerr<<"Error!"<<endl;
	cerr<<"Could not open the file "<<s<<endl;
}
void Print_Error3(char *s){
	cerr<<"Error!"<<endl;
	cerr<<"Could not open the file "<<s<<endl;
}
void Print_Error4(){
	cerr<<"Error!"<<endl;
	cerr<<"The mode is not correct."<<endl;
}
void Print_Error5(){
	cerr<<"Error!"<<endl;
	cerr<<"The file is unsupported."<<endl;
}
void Print_bmpData(BMP p){
	cerr<<endl;
    cerr<<"bfType: "<<p.file.bfType<<endl;
    cerr<<"bfSize: "<<p.file.bfSize<<endl;
    cerr<<"bfReserverd1: "<<p.file.bfReserverd1<<endl;
    cerr<<"bfReserverd2: "<<p.file.bfReserverd2<<endl;
    cerr<<"bfOffBits: "<<p.file.bfOffBits<<endl;
	cerr<<endl;
    cerr<<"biSize: "<<p.info.biSize<<endl;
    cerr<<"biWidth: "<<p.info.biWidth<<endl;
    cerr<<"biHeight: "<<p.info.biHeight<<endl;
    cerr<<"biPlanes: "<<p.info.biPlanes<<endl;
    cerr<<"biBitcount: "<<p.info.biBitcount<<endl;
    cerr<<"biCompression: "<<p.info.biCompression<<endl;
    cerr<<"biSizeImage: "<<p.info.biSizeImage<<endl;
    cerr<<"biXPelsPermeter: "<<p.info.biXPelsPermeter<<endl;
    cerr<<"biYPelsPermeter: "<<p.info.biYPelsPermeter<<endl;
    cerr<<"biClrUsed: "<<p.info.biClrUsed<<endl;
    cerr<<"biClrImportant: "<<p.info.biClrImportant<<endl;
}
int GetMode(const char *s){
	int len=strlen(s),flag=0,pos=0;
	for(int i=0;i<len;i++)if(s[i]<'0'||s[i]>'9'){flag++;pos=i;}
	for(int i=0;i<len;i++)if((s[i]<'0'||s[i]>'9')&&s[i]!='*')return -1;
	if(flag>1||(flag&&(!pos||pos==len-1)))return -1;
	return flag;
}
void Input(){
	fread(&bmp1.file,sizeof(BITMAPFILEHEADER),1,FILE_INPUT);
	fread(&bmp1.info,sizeof(BITMAPINFOHEADER),1,FILE_INPUT);
	if(bmp1.file.bfType!=0x4d42||bmp1.file.bfOffBits!=54||bmp1.info.biBitcount!=24
	||bmp1.info.biCompression!=0||bmp1.info.biSize!=40){
		Print_Error5();Close(5);
	}
	// Print_bmpData(bmp1);
	Height=bmp1.info.biHeight;
	Width=bmp1.info.biWidth;
	offset1=(4-(Width*3)%4)%4;
	bmpImg1=new IMAGEDATA[Height*Width];
	for(int i=0;i<Height;i++){
		for(int j=0;j<Width;j++){
			fread(bmpImg1+ID1(i,j),sizeof(IMAGEDATA),1,FILE_INPUT);
		}
		if(offset1!=0){
			char tmp;
			for(int j=0;j<offset1;j++){
				fread(&tmp,sizeof(char),1,FILE_INPUT);
			}
		}
	}
	bmp2=bmp1;
}
int GetNumber1(char *s){
	int len=strlen(s),x=0;
	for(int i=0;i<len;i++)x=x*10+s[i]-'0';
	return x;
}
void GetNumber2(char *s,int &x,int &y){
	int len=strlen(s),flag=0;x=y=0;
	for(int i=0;i<len;i++){
		if(s[i]=='*'){flag=1;continue;}
		if(!flag)x=x*10+s[i]-'0';
		else y=y*10+s[i]-'0';
	}
}
void Rotate(int x){
	bmpImg2=new IMAGEDATA[Height*Width];
	if(x==90){
		swap(bmp2.info.biWidth,bmp2.info.biHeight);
		for(int i=0;i<Height;i++){
			for(int j=0;j<Width;j++){
				bmpImg2[ID2(Width-j-1,i)]=bmpImg1[ID1(i,j)];
			}
		}
	}
	if(x==180){
		for(int i=0;i<Height;i++){
			for(int j=0;j<Width;j++){
				bmpImg2[ID2(Height-i-1,Width-j-1)]=bmpImg1[ID1(i,j)];
			}
		}
	}
	if(x==270){
		swap(bmp2.info.biWidth,bmp2.info.biHeight);
		for(int i=0;i<Height;i++){
			for(int j=0;j<Width;j++){
				bmpImg2[ID2(j,Height-i-1)]=bmpImg1[ID1(i,j)];
			}
		}
	}
}
int Posx(int x){return 1.0*x/bmp2.info.biHeight*bmp1.info.biHeight;}
int Posy(int y){return 1.0*y/bmp2.info.biWidth*bmp1.info.biWidth;}
IMAGEDATA operator*(IMAGEDATA A,double p){
	A.blue*=p;A.green*=p;A.red*=p;
	return A;
}
IMAGEDATA operator+(IMAGEDATA A,IMAGEDATA B){
	IMAGEDATA C=(IMAGEDATA){0,0,0};
	C.blue=A.blue+B.blue;
	C.green=A.green+B.green;
	C.red=A.red+B.red;
	return C;
}
void GetImg(int x,int y,IMAGEDATA &ans){
	int B=0,G=0,R=0;
	ans=(IMAGEDATA){0,0,0};
	int sx=Posx(x),tx=Posx(x+1),sy=Posy(y),ty=Posy(y+1);
	// ans=bmpImg1[ID1(sx,sy)];
	// return;
	if(tx==bmp1.info.biHeight)tx--;
	if(ty==bmp1.info.biWidth)ty--;
	if(Height<=bmp2.info.biHeight&&Width<=bmp2.info.biWidth){
		if(sx!=bmp1.info.biHeight-1&&sy!=bmp1.info.biWidth-1){
			double p1=1.0*x/bmp2.info.biHeight*bmp1.info.biHeight-sx;
			double p2=1.0*y/bmp2.info.biWidth*bmp1.info.biWidth-sy;
			ans=(bmpImg1[ID1(sx,sy)]*(1-p1)+bmpImg1[ID1(sx+1,sy)]*p1)*(1-p2)+
				(bmpImg1[ID1(sx,sy+1)]*(1-p1)+bmpImg1[ID1(sx+1,sy+1)]*p1)*p2;
		}
		else if(sy==bmp1.info.biWidth-1)ans=bmpImg2[ID2(x,y-1)];
		else ans=bmpImg2[ID2(x-1,y)];
		return;
	}
	for(int i=sx;i<=tx;i++){
		for(int j=sy;j<=ty;j++){
			B+=bmpImg1[ID1(i,j)].blue;
			G+=bmpImg1[ID1(i,j)].green;
			R+=bmpImg1[ID1(i,j)].red;
		}
	}
	int num=(tx-sx+1)*(ty-sy+1);
	ans.blue=B/num;
	ans.green=G/num;
	ans.red=R/num;
}
void Transform(int x,int y){
	bmp2.info.biHeight=x;
	bmp2.info.biWidth=y;
	bmpImg2=new IMAGEDATA[x*y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			GetImg(i,j,bmpImg2[ID2(i,j)]);
		}
	}
}
void Output(){
	offset2=(4-(bmp2.info.biWidth*3)%4)%4;
	bmp2.file.bfSize=(bmp2.info.biWidth*3+offset2)*bmp2.info.biHeight+54;
	bmp2.info.biSizeImage=bmp2.file.bfSize-54;
	// Print_bmpData(bmp2);
	fwrite(&bmp2.file,sizeof(BITMAPFILEHEADER),1,FILE_OUTPUT);
	fwrite(&bmp2.info,sizeof(BITMAPINFOHEADER),1,FILE_OUTPUT);
	for(int i=0;i<bmp2.info.biHeight;i++){
		for(int j=0;j<bmp2.info.biWidth;j++){
			fwrite(bmpImg2+ID2(i,j),sizeof(IMAGEDATA),1,FILE_OUTPUT);
		}
		if(offset2!=0){
			char tmp=0;
			for(int j=0;j<offset2;j++){
				fwrite(&tmp,sizeof(char),1,FILE_OUTPUT);
			}
		}
	}
}
int main(int argc,char *argv[]){
	//  cerr<<sizeof(IMAGEDATA)<<endl;
	//  cerr<<sizeof(BITMAPFILEHEADER)<<endl;
	//  cerr<<sizeof(BITMAPINFOHEADER)<<endl;
	if(argc!=4){Print_Error1();return 1;}
	
	FILE_INPUT=fopen(argv[1],"rb");
	if(FILE_INPUT==NULL){
		Print_Error2(argv[1]);
		fclose(FILE_INPUT);
		return 2;
	}
	FILE_OUTPUT=fopen(argv[2],"wb");
	if(FILE_OUTPUT==NULL){
		Print_Error3(argv[2]);
		fclose(FILE_INPUT);
		fclose(FILE_OUTPUT);
		return 3;
	}

	int MODE=GetMode(argv[3]);
	if(MODE==-1){Print_Error4();Close(4);}

	Input();

	if(!MODE){
		int x=GetNumber1(argv[3]);
		if(x!=90&&x!=180&&x!=270){Print_Error4();Close(4);}
		Rotate(x);
	}
	else{
		int x=0,y=0;
		GetNumber2(argv[3],y,x);
		if(!x||!y){Print_Error4();Close(4);}
		Transform(x,y);
	}

	Output();
	fclose(FILE_INPUT);
	fclose(FILE_OUTPUT);
	cout<<"Success!"<<endl;
	return 0;
}

#include<iostream>
#include<cstring>
#include<string>
#include<time.h>
#include<stdlib.h>
#include <math.h>
#include <fstream>
#include<stdio.h>
#include <sstream>
#include <windows.h>

using namespace std ;

class musteri
{
    private: string ad;
    private: string soyad;
	private: string tc;
	private: string tel;
	private: string adres;
	private: string  urun;
	private: string marka;
	private: string st;
	private: string gs;
public:
		
string getAd (){
	return ad;
}

void setAd (string adi){
 	ad=adi;

}	
string getsoyad(){
	return soyad;

}
void setsoyad (string soyadi){
	soyad=soyadi;

}
string gettc(){
	return tc;
}

void settc(string tcsi){
	tc=tcsi;

}

string gettel(){
	return tel;
}

void settel(string teli){
	tel=teli;
}
	string getadres(){
		return adres;
	}
	void setadres(string adresi){
		adres=adresi;
	}
	string getst(){
		return st;
	}
	void setst(string stsi){
		st=stsi;
	}
	string getgs(){
		return gs;
	}
	void setgs(string gssi){
		gs=gssi;
	}
	
	     musteri()
		{
			
		}
	void musteriEkle(musteri yeni)
		{
		  fstream bilgi;
		  bilgi.open("m��teri bilgi.txt", ios::app);
		  fstream bilgi2;
		  bilgi2.open("m��teri bilgi tlno.txt", ios::app);
		  cout<<"M��terinin ad�n� giriniz :"<<endl;  
		  string adi;
		  cin>>adi;
		  yeni.setAd(adi);
		  cout<<"M��terinin soyad�n� giriniz :"<<endl;  
		  string soyadi;
		  cin>>soyadi;
		  yeni.setsoyad(soyadi) ; 
		  cout<<"M��terinin TC kimlik numaras�n� giriniz :"<<endl;  
		  string tcsi;
		  cin>>tcsi;
		  yeni.settc(tcsi);
		  cout<<"M��terinin telefon numaras�n� giriniz :"<<endl;  
		  string teli;
		  cin>>teli;
		  yeni.settel(teli); 
		  cout<<"M��terinin adresini giriniz:"<<endl;  
		  string adresi;
		  cin>>adresi;
		  yeni.setadres(adresi);
		  cout<<"Sat�lan �r�n�n sat�� tarihini GG/AA/YYYY �eklinde giriniz :"<<endl;  
		  string stsi;
		  cin>>stsi;
		  yeni.setst(stsi);
		  cout<<"Sat�lan �r�n�n garanti s�resini giriniz :"<<endl;  
		  string gssi;
		  cin>>gssi;
		  yeni.setgs(gssi);
		  bilgi2<<yeni.tel<<"|";
		  bilgi2<<yeni.ad<<"|" ; 
		  bilgi2<<yeni.soyad<<"|";
		  bilgi2<<yeni.tc<< "|";
		  bilgi2<<yeni.adres<<"|";
		  bilgi2<<yeni.st<<"|";	  	  	  	 	  
		  bilgi2<<yeni.gs<<"|";
		  bilgi2<<endl;
		  bilgi<<yeni.tc<< "|";
		  bilgi<<yeni.ad<<"|" ; 
		  bilgi<<yeni.soyad<<"|";	
		  bilgi<<yeni.tel<<"|";
		  bilgi<<yeni.adres<<"|";
		  bilgi<<yeni.st<<"|";	  	  	  	 	  
		  bilgi<<yeni.gs<<"|";
		  bilgi<<endl;	  	  	  	  
		  
          bilgi.close();
          //BU FONKS�YONDA YEN� MU�TER�Y� DOSYAYA YAZDIRIYORUM.
			
		}
		void musteriBilgileriniListele(musteri yeni)
		{
			fstream bilgi;
			bilgi.open("m��teri bilgi.txt",ios::in);
        	string satir;

         if ( bilgi.is_open() )
		{
			cout<<"TCKN|AD|SOYAD|TEL NO|ADRES|SATI� TAR�H�|GARANT� S�RES�"<<endl;	
          	while ( !bilgi.eof() )
         	//D�NG� DOSYADAK� STR�NG �FADEN�N SONUNA KADAR �ALI�IR VE B�T�N DOSYA OKUNUR.
			{
   	        getline(bilgi, satir);
   	        const char* Kampanya = satir.c_str();
   	        for(int i = 0; i < strlen(Kampanya) ; i++)
   	        {
				cout << Kampanya[i];
				Sleep(2);
			}
            //cout << oku << endl;
            Sleep(50);
            cout << endl;
            //cout << satir << endl;
            }
          	bilgi.close();
	    }
			
		}
		void musteriAra(string arananTckn)
		{
		
			  
			  	fstream dosya;
    			dosya.open("m��teri bilgi.txt", ios::in);
    			string birMusterininBilgisi;
         		if ( dosya.is_open() )
				{	int bulundu=0;		
          			while ( !dosya.eof() )
					{
   	        			getline(dosya, birMusterininBilgisi);
   	        			int n = birMusterininBilgisi.length(); 
   	        			char char_array[n + 1]; 
	           			strcpy(char_array, birMusterininBilgisi.c_str()); 
	           			char *tckn = strtok(char_array, "|"); 
	           
	           			std::stringstream ss;
						ss << tckn;
						string tcknStr = ss.str();
	           			if(tcknStr==arananTckn)
					   {	          
	           	  		bulundu++;
	           	  		if(bulundu==1)
						{
	           	  	  	cout<<"TCKN|AD|SOYAD|TEL NO|ADRES|SATI� TAR�H�|GARANT� S�RES�"<<endl;	   
						}
	           			cout<<birMusterininBilgisi<<endl;
			   			}	             
            		}
            	if(bulundu==0)
				{
            		cout<<"Arad���n�z kriterlere uygun kay�t bulunamad�."<<endl;
				}		
          			dosya.close();
	    		}
		}
		void musteriara(string aranantelno)
		{
				fstream dosya2;
    			dosya2.open("m��teri bilgi tlno.txt", ios::in);
    			string birMusterininBilgisi;
         		if ( dosya2.is_open() )
				{	int bulundu=0;		
          			while ( !dosya2.eof() )
					{
   	        			getline(dosya2, birMusterininBilgisi);
   	        			int n = birMusterininBilgisi.length(); 
   	        			char char_array[n + 1]; 
	           			strcpy(char_array, birMusterininBilgisi.c_str()); 
	           			char *tlno = strtok(char_array, "|"); 
	           
	           			std::stringstream ss;
						ss << tlno;
						string tlnoStr = ss.str();
	           if(tlnoStr==aranantelno){	          
	           	  	bulundu++;
	           	  	if(bulundu==1){
	           	  	  cout<<"TEL NO|AD|SOYAD|TCKN|ADRES|SATI� TAR�H�|GARANT� S�RES�"<<endl;	          	  		
	           	  	
						 }
	           	cout<<birMusterininBilgisi<<endl;
	         
	          
			   }             
            		}
            	if(bulundu==0){
            		cout<<"Arad���n�z kriterlere uygun kay�t bulunamad�."<<endl;
				}	
            		
            		
          	dosya2.close();
	    }
			
			
		}
		~musteri()
		{
			
		}
};
class musteri2:public musteri
{
	protected:int satilan;
	public:
     
	musteri2()
	{
			
	}
	void sil(string sil)
	{
		fstream dosya,geciciDosya,telno;
		string musteriBilgisi;
	    string musterilerler[200];
        dosya.open("m��teri bilgi.txt", ios::in);	 
		int sayac=0;        
        while ( !dosya.eof() )
		{
        	getline(dosya, musteriBilgisi);
        	musterilerler[sayac]=musteriBilgisi;	
        	sayac++;            
        }
        
        for(int i=0;i<sayac-1;i++)
        {
        	int s;
        	s=i+1;
        	cout<<s<<"-"<<musterilerler[i]<<endl;
		}
		int silinecekkisi;
        cout<<"yukar�daki musterilerden hangisinde silme i�lemi yap�lacakt�r"<<endl;
		cin>>silinecekkisi;
	    musterilerler[silinecekkisi-1]=sil;
	    geciciDosya.open("m��teri bilgi.txt", ios::out);
     	for(int i=0; i<sayac-1;i++)    
		{
			if(i!=silinecekkisi-1)
			{
				geciciDosya<<musterilerler[i] <<endl;
			}
		
    	 	
		} 
		   geciciDosya.close();
		telno.open("m��teri bilgi tlno.txt", ios::out);
     	for(int i=0; i<sayac-1;i++)    
		{
			if(i!=silinecekkisi-1)
			{
				telno<<musterilerler[i] <<endl;
			}
		
    	 	
		} 
		  telno.close(); 
		
		
	}
	void guncele()
	{
	   fstream dosya,geciciDosya;
		string musteriBilgisi;
	    string musterilerler[200];
        dosya.open("m��teri bilgi.txt", ios::in);	 
		int sayac=0;        
        while ( !dosya.eof() )
		{
        	getline(dosya, musteriBilgisi);
        	musterilerler[sayac]=musteriBilgisi;	
        	sayac++;            
        }
        for(int i=0;i<sayac-1;i++)
        {
        	int s;
        	s=i+1;
        	cout<<s<<"-"<<musterilerler[i]<<endl;
		}
		int guncelenecekkisi;
		string guncel;
        cout<<"yukar�daki musterilerden hangisinde guncelleme yap�lacakt�r"<<endl;
		cin>>guncelenecekkisi;
		cout<<"g�nceliyece�iniz ki�inin bilgilerini a�a��daki gibi giriniz"<<endl;
		 cout<<"TCKN|AD|SOYAD|TEL NO|ADRES|SATI� TAR�H�|GARANT� S�RES�"<<endl;	 	 
		cin>>guncel;
		 musterilerler[guncelenecekkisi-1]=guncel;
	    geciciDosya.open("m��teri bilgi.txt", ios::out);
     	for(int i=0; i<sayac;i++)    
		{
    	 	geciciDosya<<musterilerler[i] <<endl;
		} 
		   geciciDosya.close();
	}
	~musteri2()
	{
		
	}
};
void urunListele(){
		 
 	fstream dosya;
    dosya.open("�r�n bilgi.txt", ios::in);
    string oku2;
    
         if ( dosya.is_open() )
		{			
          while ( !dosya.eof() )
			{
   	        getline(dosya, oku2);
   	        const char* Kampanya = oku2.c_str();
   	        for(int i = 0; i < strlen(Kampanya) ; i++)
   	        {
				cout << Kampanya[i];
				Sleep(5);
			}
            //cout << oku << endl;
            Sleep(25);
            cout << endl;
            //cout << oku2 << endl;
            }
          dosya.close();
	    }
}


class urun :
 public musteri2
{
	public:
	int bilgisayarasus;
	int bilgisayarapple;
	int bilgisayrlg;
	int bilgisayarhp;
	int telefonapple;
	int telefonsamsung;
	int telefonlg;
	int telefonsony;
	int	kulaklikapple;
	int kulakliksamsung;
	int kulakliklg;
	int kulakliksony;
	int kamerahuwavi;
	int kameracanon;
	int kameraasus;
	int tableapple;
	int tabletsamsung;
	int tabletlenova;
	urun()
	{
		bilgisayarasus=0;
		bilgisayarapple=0;
		bilgisayrlg=0;
		bilgisayarhp=0;
		telefonapple=0;
		telefonsamsung=0;
		telefonlg=0;
		telefonsony=0;
		kulaklikapple=0;
		kulakliksamsung=0;
		kulakliklg=0;
		kulakliksony=0;
		kamerahuwavi=0;
		kameracanon=0;
		kameraasus=0;
		tableapple=0;
		tabletsamsung=0;
		tabletlenova=0;
		}
		void urunekle(urun g)
		{
			urunListele();	
				
			int satilacakUrun,t1;			
			cout<<"Yukar�daki markalardan hangisine �r�n eklenecektir"<<endl;
			cin>>satilacakUrun;
			fstream dosya,geciciDosya;
	
	
		    string urunBilgisi,satisiYapilacakUrun;
	
		    string urunler[18];
	        dosya.open("�r�n bilgi.txt", ios::in);	 
			int sayac=0;        
	        while ( !dosya.eof() )
			{
   	        	getline(dosya, urunBilgisi);
   	        	urunler[sayac]=urunBilgisi;	
            	sayac++;            
            }
             
	         satisiYapilacakUrun=urunler[satilacakUrun-1];  
	          int n = satisiYapilacakUrun.length(); 
	        
	          char char_array[n + 1]; 
	           strcpy(char_array, satisiYapilacakUrun.c_str()); 
				int alinanurunsayi;
				cout<<"ka� �r�n al�nd�"<<endl;
				cin>> alinanurunsayi;	
				char *urunIsmi = strtok(char_array, ":"); 
	  			char *urunAdedi =  strtok(NULL, ":");  		
				int urunAdediInt= atoi(urunAdedi);				
				std::string guncellenmisUrunBilgisi;
				std::stringstream ss;
				ss << urunIsmi << ":"<< urunAdediInt+alinanurunsayi;
				guncellenmisUrunBilgisi = ss.str();
			
				urunler[satilacakUrun-1]=guncellenmisUrunBilgisi;

    //g�ncellenmi� halini dosyaya yaz�yoruz
  
    	 geciciDosya.open("�r�n bilgi.txt", ios::out);
    	 for(int i=0; i<17;i++)    	{
    	 	 	 geciciDosya<<urunler[i] <<endl;
		 } 
		    geciciDosya.close();
    	    cout<<"Ana men�ye d�nmek i�in herhangi bir tu�a bas�n"<<endl;
		    cin>>t1;
		    system("cls");
			}
	void urunsat(musteri yeni)
		{
				int satilacakUrun,t1;
			do{
			
			urunListele();	
				
					
			cout<<"Yukar�daki markalardan hangisine �r�n sat�lacaktir"<<endl;
			cin>>satilacakUrun;
			fstream dosya,geciciDosya;
	
	
		    string urunBilgisi,satisiYapilacakUrun;
	
		    string urunler[18];
	        dosya.open("�r�n bilgi.txt", ios::in);	 
			int sayac=0;        
	        while ( !dosya.eof() )
			{
   	        	getline(dosya, urunBilgisi);
   	        	urunler[sayac]=urunBilgisi;	
            	sayac++;            
            }
             
	           satisiYapilacakUrun=urunler[satilacakUrun-1];  
	           int n = satisiYapilacakUrun.length(); 
	        
	            char char_array[n + 1]; 
	            strcpy(char_array, satisiYapilacakUrun.c_str()); 	
	  			char *urunIsmi = strtok(char_array, ":"); 
	  			char *urunAdedi =  strtok(NULL, ":");  		
				int urunAdediInt= atoi(urunAdedi);				 
				std::string guncellenmisUrunBilgisi;
				std::stringstream ss;
				ss << urunIsmi << ":"<< urunAdediInt-1;
				guncellenmisUrunBilgisi = ss.str();
				urunler[satilacakUrun-1]=guncellenmisUrunBilgisi;

    //g�ncellenmi� halini dosyaya yaz�yoruz
  
    	 geciciDosya.open("�r�n bilgi.txt", ios::out);
    	 for(int i=0; i<17;i++)    	{
    	 	 	 geciciDosya<<urunler[i] <<endl;
		 } 
		   geciciDosya.close();
    	 
    	 	yeni.musteriEkle(yeni);
    	 
			     cout<<"Ana men�ye d�nmek i�in herhangi bir tu�a bas�n"<<endl;
		    cin>>t1;
		
			
			
		    }
		    while(t1==2);
				 	 
		
		}
};
int main()
{
	system("color F5");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
 int IslemKodu ;
 setlocale(LC_ALL,"TURKISH");
 //T�RK�E KARAKTER KULANAB�LMEM ���N GEREKL� KOD.
 do{

 cout<<" TA�LI T�CARET TEKNOLOJ� MA�AZASINA HO� GELD�N�Z"<<endl;
 cout<<"***********************************************"<<endl;
 cout<<" 1. M��TER� SATI� B�LG�LER�"<<endl;
 cout<<" 2. TANIMLI �R�N B�LG�LER�"<<endl;
 cout<<" 3. KAMPANYA B�LG�LER�"<<endl;
 cout<<" 4. YEN� �R�N TANIMLAMA"<<endl;
 cout<<" 5. �R�N SATI� ��LEMLER�"<<endl;
 cout<<" 6. M��TER� SATI� ARAMA"<<endl;
 cout<<" 7. M��TER� GUNCELE"<<endl;
 cout<<" 8. M��TER� S�L"<<endl;
 cout<<" 9. �IKI� YAP"<<endl;
 cout<<" "<<endl;
 cout<<"***********************************************"<<endl;
 cout<<"SE�T���N�Z ��LEM KODUNU G�R�N�Z"<<endl;
 cin>>IslemKodu;
 system("cls");
 //SAYFAYI TEM�ZLEYEN KOD.
 	musteri yeni;
 	urun g;
 	musteri2 yeni2;
 		char devam; 	
 	switch (IslemKodu){
 		case 1:{
			system("color F1");
 			yeni.musteriBilgileriniListele(yeni);
 			cout<<"Ana men�ye d�nmek i�in herhangi bir tu�a bas�n "<<endl;
 			cin>>devam;	
 				 system("cls");
 				 break;
	 	};
 		 case 2:{
 		 	system("color F2");
			urunListele();
			cout<<"Ana men�ye d�nmek i�in herhangi bir tu�a bas�n "<<endl;
 			cin>>devam;	
 				 system("cls");
 				 break;
	 	};	
		 case 3:{
		 	system("color F4");
		 	char sec;
		 		
 			fstream kamp;
 			kamp.open("kampanya bilgi.txt",ios::in);
 	  		string oku;

         	if ( kamp.is_open() )
			{
          		while ( !kamp.eof())
				{
   	        		getline(kamp, oku);
   	        		const char* Kampanya = oku.c_str();
   	        		for(int i = 0; i < strlen(Kampanya) ; i++)
   	        		{
						cout << Kampanya[i];
						Sleep(10);
					}
            		//cout << oku << endl;
            		Sleep(500);
            		cout << endl;
            	}
          		kamp.close();
	    	}
	cout<<"Ana men�ye d�nmek i�in herhangi bir tu�a bas�n "<<endl;
	    cin>>sec;

	   
	break;
	 	};	
		 case 4:{		 
		 system("color F5");	
		 	g.urunekle(g);		 	
			break;
		};
	 	case 5:{
	 		system("color F6");
	 		g.urunsat(yeni);
		
			break;
	 };
 	 	case 6:{
 	 		system("color F8");
 	 		int aramaislemturu;
 	 		cout<<"ARAMA ��LEM�N� NASIL YAPMAK �STERS�N�Z"<<endl;
 	 		cout<<"1-TCKN G�REREK"<<endl;
 	 		cout<<"2-TEL NO G�REREK"<<endl;
 	 		cin>>aramaislemturu;
 	 		if(aramaislemturu==1)
 	 		{
 	 				string arananTckn;
			        cout<<"ARAMAK �STED���N�Z TCKN'Y� G�R�N�Z:"<<endl;	
			        cin >>arananTckn;
 	 				yeni.musteriAra(arananTckn);
			  }
			if(aramaislemturu==2)
			{
				string aranantelno;
				cout<<"ARAMAK iSTED���N�Z TEL NO'YU G�R�N�Z:"<<endl;
				cin>>aranantelno;
				yeni.musteriara(aranantelno);
			  }  
	 	
	 		cout<<"Ana men�ye d�nmek i�in herhangi bir tu�a bas�n "<<endl;
 			cin>>devam;	
 			 system("cls");
			break;
	 };
	 case 7:{
	 	system("color F9");
	 	g.guncele();
	 	
		break;
	 };
	 case 8:{
	 	system("color F3");
	 	string sil="";
	 	g.sil(sil);
		break;
	 };
}

  system("cls");
}
while(IslemKodu!=9);
}


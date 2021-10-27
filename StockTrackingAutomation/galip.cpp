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
		  bilgi.open("müþteri bilgi.txt", ios::app);
		  fstream bilgi2;
		  bilgi2.open("müþteri bilgi tlno.txt", ios::app);
		  cout<<"Müþterinin adýný giriniz :"<<endl;  
		  string adi;
		  cin>>adi;
		  yeni.setAd(adi);
		  cout<<"Müþterinin soyadýný giriniz :"<<endl;  
		  string soyadi;
		  cin>>soyadi;
		  yeni.setsoyad(soyadi) ; 
		  cout<<"Müþterinin TC kimlik numarasýný giriniz :"<<endl;  
		  string tcsi;
		  cin>>tcsi;
		  yeni.settc(tcsi);
		  cout<<"Müþterinin telefon numarasýný giriniz :"<<endl;  
		  string teli;
		  cin>>teli;
		  yeni.settel(teli); 
		  cout<<"Müþterinin adresini giriniz:"<<endl;  
		  string adresi;
		  cin>>adresi;
		  yeni.setadres(adresi);
		  cout<<"Satýlan ürünün satýþ tarihini GG/AA/YYYY þeklinde giriniz :"<<endl;  
		  string stsi;
		  cin>>stsi;
		  yeni.setst(stsi);
		  cout<<"Satýlan ürünün garanti süresini giriniz :"<<endl;  
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
          //BU FONKSÝYONDA YENÝ MUÞTERÝYÝ DOSYAYA YAZDIRIYORUM.
			
		}
		void musteriBilgileriniListele(musteri yeni)
		{
			fstream bilgi;
			bilgi.open("müþteri bilgi.txt",ios::in);
        	string satir;

         if ( bilgi.is_open() )
		{
			cout<<"TCKN|AD|SOYAD|TEL NO|ADRES|SATIÞ TARÝHÝ|GARANTÝ SÜRESÝ"<<endl;	
          	while ( !bilgi.eof() )
         	//DÖNGÜ DOSYADAKÝ STRÝNG ÝFADENÝN SONUNA KADAR ÇALIÞIR VE BÜTÜN DOSYA OKUNUR.
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
    			dosya.open("müþteri bilgi.txt", ios::in);
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
	           	  	  	cout<<"TCKN|AD|SOYAD|TEL NO|ADRES|SATIÞ TARÝHÝ|GARANTÝ SÜRESÝ"<<endl;	   
						}
	           			cout<<birMusterininBilgisi<<endl;
			   			}	             
            		}
            	if(bulundu==0)
				{
            		cout<<"Aradýðýnýz kriterlere uygun kayýt bulunamadý."<<endl;
				}		
          			dosya.close();
	    		}
		}
		void musteriara(string aranantelno)
		{
				fstream dosya2;
    			dosya2.open("müþteri bilgi tlno.txt", ios::in);
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
	           	  	  cout<<"TEL NO|AD|SOYAD|TCKN|ADRES|SATIÞ TARÝHÝ|GARANTÝ SÜRESÝ"<<endl;	          	  		
	           	  	
						 }
	           	cout<<birMusterininBilgisi<<endl;
	         
	          
			   }             
            		}
            	if(bulundu==0){
            		cout<<"Aradýðýnýz kriterlere uygun kayýt bulunamadý."<<endl;
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
        dosya.open("müþteri bilgi.txt", ios::in);	 
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
        cout<<"yukarýdaki musterilerden hangisinde silme iþlemi yapýlacaktýr"<<endl;
		cin>>silinecekkisi;
	    musterilerler[silinecekkisi-1]=sil;
	    geciciDosya.open("müþteri bilgi.txt", ios::out);
     	for(int i=0; i<sayac-1;i++)    
		{
			if(i!=silinecekkisi-1)
			{
				geciciDosya<<musterilerler[i] <<endl;
			}
		
    	 	
		} 
		   geciciDosya.close();
		telno.open("müþteri bilgi tlno.txt", ios::out);
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
        dosya.open("müþteri bilgi.txt", ios::in);	 
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
        cout<<"yukarýdaki musterilerden hangisinde guncelleme yapýlacaktýr"<<endl;
		cin>>guncelenecekkisi;
		cout<<"günceliyeceðiniz kiþinin bilgilerini aþaðýdaki gibi giriniz"<<endl;
		 cout<<"TCKN|AD|SOYAD|TEL NO|ADRES|SATIÞ TARÝHÝ|GARANTÝ SÜRESÝ"<<endl;	 	 
		cin>>guncel;
		 musterilerler[guncelenecekkisi-1]=guncel;
	    geciciDosya.open("müþteri bilgi.txt", ios::out);
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
    dosya.open("ürün bilgi.txt", ios::in);
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
			cout<<"Yukarýdaki markalardan hangisine ürün eklenecektir"<<endl;
			cin>>satilacakUrun;
			fstream dosya,geciciDosya;
	
	
		    string urunBilgisi,satisiYapilacakUrun;
	
		    string urunler[18];
	        dosya.open("ürün bilgi.txt", ios::in);	 
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
				cout<<"kaç ürün alýndý"<<endl;
				cin>> alinanurunsayi;	
				char *urunIsmi = strtok(char_array, ":"); 
	  			char *urunAdedi =  strtok(NULL, ":");  		
				int urunAdediInt= atoi(urunAdedi);				
				std::string guncellenmisUrunBilgisi;
				std::stringstream ss;
				ss << urunIsmi << ":"<< urunAdediInt+alinanurunsayi;
				guncellenmisUrunBilgisi = ss.str();
			
				urunler[satilacakUrun-1]=guncellenmisUrunBilgisi;

    //güncellenmiþ halini dosyaya yazýyoruz
  
    	 geciciDosya.open("ürün bilgi.txt", ios::out);
    	 for(int i=0; i<17;i++)    	{
    	 	 	 geciciDosya<<urunler[i] <<endl;
		 } 
		    geciciDosya.close();
    	    cout<<"Ana menüye dönmek için herhangi bir tuþa basýn"<<endl;
		    cin>>t1;
		    system("cls");
			}
	void urunsat(musteri yeni)
		{
				int satilacakUrun,t1;
			do{
			
			urunListele();	
				
					
			cout<<"Yukarýdaki markalardan hangisine ürün satýlacaktir"<<endl;
			cin>>satilacakUrun;
			fstream dosya,geciciDosya;
	
	
		    string urunBilgisi,satisiYapilacakUrun;
	
		    string urunler[18];
	        dosya.open("ürün bilgi.txt", ios::in);	 
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

    //güncellenmiþ halini dosyaya yazýyoruz
  
    	 geciciDosya.open("ürün bilgi.txt", ios::out);
    	 for(int i=0; i<17;i++)    	{
    	 	 	 geciciDosya<<urunler[i] <<endl;
		 } 
		   geciciDosya.close();
    	 
    	 	yeni.musteriEkle(yeni);
    	 
			     cout<<"Ana menüye dönmek için herhangi bir tuþa basýn"<<endl;
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
 //TÜRKÇE KARAKTER KULANABÝLMEM ÝÇÝN GEREKLÝ KOD.
 do{

 cout<<" TAÞLI TÝCARET TEKNOLOJÝ MAÐAZASINA HOÞ GELDÝNÝZ"<<endl;
 cout<<"***********************************************"<<endl;
 cout<<" 1. MÜÞTERÝ SATIÞ BÝLGÝLERÝ"<<endl;
 cout<<" 2. TANIMLI ÜRÜN BÝLGÝLERÝ"<<endl;
 cout<<" 3. KAMPANYA BÝLGÝLERÝ"<<endl;
 cout<<" 4. YENÝ ÜRÜN TANIMLAMA"<<endl;
 cout<<" 5. ÜRÜN SATIÞ ÝÞLEMLERÝ"<<endl;
 cout<<" 6. MÜÞTERÝ SATIÞ ARAMA"<<endl;
 cout<<" 7. MÜÞTERÝ GUNCELE"<<endl;
 cout<<" 8. MÜÞTERÝ SÝL"<<endl;
 cout<<" 9. ÇIKIÞ YAP"<<endl;
 cout<<" "<<endl;
 cout<<"***********************************************"<<endl;
 cout<<"SEÇTÝÐÝNÝZ ÝÞLEM KODUNU GÝRÝNÝZ"<<endl;
 cin>>IslemKodu;
 system("cls");
 //SAYFAYI TEMÝZLEYEN KOD.
 	musteri yeni;
 	urun g;
 	musteri2 yeni2;
 		char devam; 	
 	switch (IslemKodu){
 		case 1:{
			system("color F1");
 			yeni.musteriBilgileriniListele(yeni);
 			cout<<"Ana menüye dönmek için herhangi bir tuþa basýn "<<endl;
 			cin>>devam;	
 				 system("cls");
 				 break;
	 	};
 		 case 2:{
 		 	system("color F2");
			urunListele();
			cout<<"Ana menüye dönmek için herhangi bir tuþa basýn "<<endl;
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
	cout<<"Ana menüye dönmek için herhangi bir tuþa basýn "<<endl;
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
 	 		cout<<"ARAMA ÝÞLEMÝNÝ NASIL YAPMAK ÝSTERSÝNÝZ"<<endl;
 	 		cout<<"1-TCKN GÝREREK"<<endl;
 	 		cout<<"2-TEL NO GÝREREK"<<endl;
 	 		cin>>aramaislemturu;
 	 		if(aramaislemturu==1)
 	 		{
 	 				string arananTckn;
			        cout<<"ARAMAK ÝSTEDÝÐÝNÝZ TCKN'YÝ GÝRÝNÝZ:"<<endl;	
			        cin >>arananTckn;
 	 				yeni.musteriAra(arananTckn);
			  }
			if(aramaislemturu==2)
			{
				string aranantelno;
				cout<<"ARAMAK iSTEDÝÐÝNÝZ TEL NO'YU GÝRÝNÝZ:"<<endl;
				cin>>aranantelno;
				yeni.musteriara(aranantelno);
			  }  
	 	
	 		cout<<"Ana menüye dönmek için herhangi bir tuþa basýn "<<endl;
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


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class insan {
public:
    string isim;
    int numara;
    int sira;
};
insan kisi[500];

class yontem {
public:
    string yontem_adi;
    int islem_sayisi;
};
yontem dizi[7];

void rastgele_veri_olustur(){

    char ad[10];
    int i , j ;

    ofstream olustur("rastgele.txt" , ios::out);

    for(i=0 ; i<500 ; i++){
        kisi[i].sira=i+1;
    tekrar:
        kisi[i].numara=140202000+rand()%1000;

        for(j=0 ; j<i ; j++){
            if(kisi[i].numara==kisi[j].numara){
                goto tekrar;
            }
        }

        for(j=0 ; j<10 ; j++){
            ad[j]=97+rand()%26;
        }
        kisi[i].isim=ad;

        olustur<< setw(3)<< kisi[i].sira<< " "<< kisi[i].numara<< "  "<< kisi[i].isim;
    }
    olustur.close();
}

insan bkl_hash[500]={};
void bolen_kalan_lineer(){

    ifstream oku("rastgele.txt" , ios::in);

    insan okunan;
    int i;

    for(i=0 ; i<500 ; i++){
        oku>>okunan.sira>> okunan.numara>> okunan.isim;
        int yer=okunan.numara%500;

        ekle:
        if(bkl_hash[yer].numara==0){
            bkl_hash[yer].sira=okunan.sira;
            bkl_hash[yer].numara=okunan.numara;
            bkl_hash[yer].isim=okunan.isim;
        }
        else{
            yer++;
            if(yer>=500)
                yer=yer-500;
            goto ekle;
        }
    }

    ofstream yaz("bolen_kalan_lineer.txt" , ios::out);

    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< bkl_hash[i].sira<< " "<< bkl_hash[i].numara<< " "<< bkl_hash[i].isim<< endl;
    }
}

insan kl_hash[500]={};
void katlama_lineer(){

    ifstream oku("rastgele.txt" , ios::in);

    insan okunan;
    int i ;

    for(i=0 ; i<500 ; i++){
        oku>>okunan.sira>> okunan.numara>> okunan.isim;

        int gecici;

        gecici=okunan.numara%1000;

        int j=0 , yer;
        int sayi[3]={};

        while(gecici>=1){
            sayi[j]=gecici%10;
            gecici=gecici/10;
            j++;
        }

        yer=((0+2+sayi[0])%10)*100+((4+0+sayi[1])%10)*10+((1+2+sayi[2])%10)*1;
        yer=yer%500;

        ekle:
        if(kl_hash[yer].numara==0){
            kl_hash[yer].isim=okunan.isim;
            kl_hash[yer].numara=okunan.numara;
            kl_hash[yer].sira=okunan.sira;
        }
        else{
            yer++;
            if(yer>=500)
                yer=yer-500;
            goto ekle;
        }
    }

    ofstream yaz("katlama_lineer.txt" , ios::out);

    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< kl_hash[i].sira<< " "<< kl_hash[i].numara<< " "<< kl_hash[i].isim<< endl;
    }
}

insan kol_hash[500]={};
void kare_ortasi_lineer(){
    ifstream oku("rastgele.txt" , ios::in);

    insan okunan;
    int i ;
    long long yer;

    for(i=0 ; i<500 ; i++){
        oku>>okunan.sira>> okunan.numara>> okunan.isim;

        yer = okunan.numara;
        yer=yer*yer;
        yer=yer/10000000;
        yer=yer%500;


    ekle:
        if(kol_hash[yer].numara==0){
            kol_hash[yer].isim=okunan.isim;
            kol_hash[yer].numara=okunan.numara;
            kol_hash[yer].sira=okunan.sira;
        }
        else{
            yer++;
            if(yer>=500)
                yer=yer-500;
            goto ekle;
        }
    }

    ofstream yaz("kare_ortasi_lineer.txt" , ios::out);

    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< kol_hash[i].sira<< " "<< kol_hash[i].numara<< " "<< kol_hash[i].isim<< endl;
    }

}

insan bka_hash[500]={};
insan bka_tasan[500]={};
void bolen_kalan_ayrik(){

    ifstream oku("rastgele.txt" , ios::in);

    insan okunan;
    int i;

    for(i=0 ; i<500 ; i++){
        oku>>okunan.sira>> okunan.numara>> okunan.isim;
        int yer=okunan.numara%500;

        if(bka_hash[yer].numara==0){
            bka_hash[yer].sira=okunan.sira;
            bka_hash[yer].numara=okunan.numara;
            bka_hash[yer].isim=okunan.isim;
            continue;
        }
        ekle:
        if(bka_tasan[yer].numara==0){
            bka_tasan[yer].sira=okunan.sira;
            bka_tasan[yer].numara=okunan.numara;
            bka_tasan[yer].isim=okunan.isim;
        }
        else{
            yer++;
            if(yer>=500)
                yer=yer-500;
            goto ekle;
        }
    }

    ofstream yaz("bolen_kalan_ayrik.txt" , ios::out);
    yaz<< "HASH:"<< endl;
    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< bka_hash[i].sira<< " "<< bka_hash[i].numara<< " "<< bka_hash[i].isim<< endl;
    }
    yaz<< "TASAN:"<< endl;
    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< bka_tasan[i].sira<< " "<< bka_tasan[i].numara<< " "<< bka_tasan[i].isim<< endl;
    }
}

insan ka_hash[500]={};
insan ka_tasan[500]={};
void katlama_ayrik(){
    ifstream oku("rastgele.txt" , ios::in);

    insan okunan;
    int i ;

    for(i=0 ; i<500 ; i++){
        oku>>okunan.sira>> okunan.numara>> okunan.isim;

        int gecici;

        gecici=okunan.numara%1000;

        int j=0 , yer;
        int sayi[3]={};

        while(gecici>=1){
            sayi[j]=gecici%10;
            gecici=gecici/10;
            j++;
        }

        yer=((0+2+sayi[0])%10)*100+((4+0+sayi[1])%10)*10+((1+2+sayi[2])%10)*1;
        yer=yer%500;

        if(ka_hash[yer].numara==0){
            ka_hash[yer].isim=okunan.isim;
            ka_hash[yer].numara=okunan.numara;
            ka_hash[yer].sira=okunan.sira;
            continue;
        }
        ekle:
        if(ka_tasan[yer].numara==0){
            ka_tasan[yer].isim=okunan.isim;
            ka_tasan[yer].numara=okunan.numara;
            ka_tasan[yer].sira=okunan.sira;
        }
        else{
            yer++;
            if(yer>=500)
                yer=yer-500;
            goto ekle;
        }
    }

    ofstream yaz("katlama_ayrik.txt" , ios::out);
    yaz<< "HASH:"<< endl;
    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< ka_hash[i].sira<< " "<< ka_hash[i].numara<< " "<< ka_hash[i].isim<< endl;
    }
    yaz<< "TASAN:"<< endl;
    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< ka_tasan[i].sira<< " "<< ka_tasan[i].numara<< " "<< ka_tasan[i].isim<< endl;
    }

}

insan koa_hash[500]={};
insan koa_tasan[500]={};
void kare_ortasi_ayrik(){
    ifstream oku("rastgele.txt" , ios::in);

    insan okunan;
    int i ;
    long long yer;

    for(i=0 ; i<500 ; i++){
        oku>>okunan.sira>> okunan.numara>> okunan.isim;

        yer = okunan.numara;
        yer=yer*yer;
        yer=yer/10000000;
        yer=yer%500;

        if(koa_hash[yer].numara==0){
            koa_hash[yer].isim=okunan.isim;
            koa_hash[yer].numara=okunan.numara;
            koa_hash[yer].sira=okunan.sira;
            continue;
        }
        ekle:
        if(koa_tasan[yer].numara==0){
            koa_tasan[yer].isim=okunan.isim;
            koa_tasan[yer].numara=okunan.numara;
            koa_tasan[yer].sira=okunan.sira;
        }
        else{
            yer++;
            if(yer>=500)
                yer=yer-500;
            goto ekle;
        }
    }

    ofstream yaz("kare_ortasi_ayrik.txt" , ios::out);
    yaz<< "HASH:"<< endl;
    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< koa_hash[i].sira<< " "<< koa_hash[i].numara<< " "<< koa_hash[i].isim<< endl;
    }
    yaz<< "TASAN:"<< endl;
    for(i=0 ; i<500 ; i++){
        yaz<< setw(3)<< i+1<< ". "<< setw(3)<< koa_tasan[i].sira<< " "<< koa_tasan[i].numara<< " "<< koa_tasan[i].isim<< endl;
    }
}

int arama_rastgele(int numara){
    static int sayac_rastgele=0;
    ifstream oku("rastgele.txt" , ios::in);
    static int r_bulunan=0;sayac_rastgele++;
    insan okunan;sayac_rastgele++;
    while(1){
        oku>> okunan.sira>> okunan.numara>> okunan.isim;sayac_rastgele++;

        if(numara==okunan.numara){
            sayac_rastgele++;
            r_bulunan++;sayac_rastgele++;
            break;
        }
    }
    return sayac_rastgele;
}

int arama_bkl(int numara){
    static int sayac_bkl=0;

    int yer=numara%500; sayac_bkl++;

    static int bkl_bulunan=0; sayac_bkl++;

    while(1){
        if(numara==bkl_hash[yer].numara){
            sayac_bkl++;
            bkl_bulunan++; sayac_bkl++;
            break;
        }
        else{
            sayac_bkl++;
            yer++; sayac_bkl++;
            if(yer>=500){
                sayac_bkl++;
                yer=yer-500;sayac_bkl++;
            }

        }
    }
    return sayac_bkl;

}

int arama_kl(int numara){
    static int sayac_kl=0;
    int gecici=numara%1000;sayac_kl++;

    int j=0 , yer;sayac_kl++;sayac_kl++;
    int sayi[3]={};sayac_kl++;

    while(gecici>=1){
            sayac_kl++;
        sayi[j]=gecici%10;sayac_kl++;
        gecici=gecici/10;sayac_kl++;
        j++;sayac_kl++;
    }

    yer=((0+2+sayi[0])%10)*100+((4+0+sayi[1])%10)*10+((1+2+sayi[2])%10)*1;sayac_kl++;
    yer=yer%500;sayac_kl++;

    static int kl_bulunan=0;sayac_kl++;
    int i;sayac_kl++;

    for(i=0 ; i<500 ; i++){
            sayac_kl++;
        if(numara==kl_hash[yer].numara){
            sayac_kl++;
            kl_bulunan++;sayac_kl++;
            break;
        }
        else{
            sayac_kl++;
            yer++;sayac_kl++;
            if(yer>=500){
                sayac_kl++;
                yer=yer-500;sayac_kl++;
            }

        }
    }

    return sayac_kl;
}

int arama_kol(int numara){
    static int sayac_kol=0;
    long long yer;sayac_kol++;

    yer =numara;sayac_kol++;
    yer=yer*yer;sayac_kol++;
    yer=yer/10000000;sayac_kol++;
    yer=yer%500;sayac_kol++;

    static int kol_bulunan=0;sayac_kol++;
    int i;sayac_kol++;

    for(i=0 ; i<500 ; i++){
            sayac_kol++;
        if(numara==kol_hash[yer].numara){
            sayac_kol++;
            kol_bulunan++;sayac_kol++;
            break;
        }
        else{
            sayac_kol++;
            yer++;sayac_kol++;
            if(yer>=500){
                sayac_kol++;
                yer=yer-500;sayac_kol++;
            }

        }
    }

    return sayac_kol;

}

int arama_bka(int numara){
    static int sayac_bka=0;
    int yer=numara%500;sayac_bka++;

    static int bka_bulunan=0;sayac_bka++;

    if(numara==bka_hash[yer].numara){
            sayac_bka++;
        bka_bulunan++;sayac_bka++;
        goto bitir;
    }
    tekrar:
    if(numara==bka_tasan[yer].numara){
        sayac_bka++;
        bka_bulunan++;sayac_bka++;
        goto bitir;
    }
    else{
        sayac_bka++;
        yer++;sayac_bka++;
            if(yer>=500){
                sayac_bka++;
                yer=yer-500;sayac_bka++;
            }

            goto tekrar;
    }
    bitir:
    return sayac_bka;
}

int arama_ka(int numara){
    static int sayac_ka=0;
    int gecici=numara%1000;sayac_ka++;

    int j=0 , yer;sayac_ka++;sayac_ka++;
    int sayi[3]={};sayac_ka++;

    while(gecici>=1){
            sayac_ka++;
        sayi[j]=gecici%10;sayac_ka++;
        gecici=gecici/10;sayac_ka++;
        j++;sayac_ka++;
    }

    yer=((0+2+sayi[0])%10)*100+((4+0+sayi[1])%10)*10+((1+2+sayi[2])%10)*1;sayac_ka++;
    yer=yer%500;sayac_ka++;

    static int ka_bulunan=0;sayac_ka++;

    if(numara==ka_hash[yer].numara){
            sayac_ka++;
        ka_bulunan++;sayac_ka++;
        goto bitir;
    }
    tekrar:
    if(numara==ka_tasan[yer].numara){
        sayac_ka++;
        ka_bulunan++;sayac_ka++;
        goto bitir;
    }
    else{
        sayac_ka++;
        yer++;sayac_ka++;
            if(yer>=500){
                sayac_ka++;
                yer=yer-500;sayac_ka++;
            }

            goto tekrar;
    }
    bitir:
    return sayac_ka;
}

int arama_koa(int numara){
    static int sayac_koa=0;
    long long yer;sayac_koa++;

    yer =numara;sayac_koa++;
    yer=yer*yer;sayac_koa++;
    yer=yer/10000000;sayac_koa++;
    yer=yer%500;sayac_koa++;

    static int koa_bulunan=0;sayac_koa++;

    if(numara==koa_hash[yer].numara){
            sayac_koa++;
        koa_bulunan++;sayac_koa++;
        goto bitir;
    }
    tekrar:
    if(numara==koa_tasan[yer].numara){
        sayac_koa++;
        koa_bulunan++;sayac_koa++;
        goto bitir;
    }
    else{
        sayac_koa++;
        yer++;sayac_koa++;
            if(yer>=500){
                sayac_koa++;
                yer=yer-500;sayac_koa++;
            }

            goto tekrar;
    }
    bitir:
    return sayac_koa;
}

void olustur(){

    rastgele_veri_olustur();

    bolen_kalan_lineer();
    katlama_lineer();
    kare_ortasi_lineer();

    bolen_kalan_ayrik();
    katlama_ayrik();
    kare_ortasi_ayrik();
}

yontem tarama(){
    ifstream oku("rastgele.txt" , ios::in);
    insan okunan;
    int i , j;
    yontem en_kisa;

    dizi[0].yontem_adi= "Rastgele";

    dizi[1].yontem_adi= "Bolen Kalan Lineer";
    dizi[2].yontem_adi= "Katlama Lineer";
    dizi[3].yontem_adi= "Kare Ortasi Lineer";

    dizi[4].yontem_adi= "Bolen Kalan Ayrik Tasma";
    dizi[5].yontem_adi= "Katlama Ayrik Tasma";
    dizi[6].yontem_adi= "Kare Ortasi Ayrik Tasma";

    for(i=0 ; i<500 ; i++){
        oku>> okunan.sira>> okunan.numara>> okunan.isim;

        dizi[0].islem_sayisi=arama_rastgele(okunan.numara);

        dizi[1].islem_sayisi=arama_bkl(okunan.numara);
        dizi[2].islem_sayisi=arama_kl(okunan.numara);
        dizi[3].islem_sayisi=arama_kol(okunan.numara);

        dizi[4].islem_sayisi=arama_bka(okunan.numara);
        dizi[5].islem_sayisi=arama_ka(okunan.numara);
        dizi[6].islem_sayisi=arama_koa(okunan.numara);

    }

    cout<< endl<< "Rastgele Olusturulan Dosyasindaki 500 Kisi **"<< dizi[0].islem_sayisi<<"** Islemde Bulundu."<< endl<< endl;

    cout<< "Bolen Kalan lineer Dosyasindaki 500 Kisi **"<< dizi[1].islem_sayisi<<"** Islemde Bulundu."<< endl;
    cout<< "Katlama Lineer Dosyasindaki 500 Kisi **"<< dizi[2].islem_sayisi<<"** Islemde Bulundu."<< endl;
    cout<< "Kare Ortasi Lineer Dosyasindaki 500 Kisi **"<< dizi[3].islem_sayisi<<"** Islemde Bulundu."<< endl<< endl;

    cout<< "Bolen Kalan Ayrik Dosyasindaki 500 Kisi **"<< dizi[4].islem_sayisi<<"** Islemde Bulundu."<< endl;
    cout<< "Katlama Ayrik Dosyasindaki 500 Kisi **"<< dizi[5].islem_sayisi<<"** Islemde Bulundu."<< endl;
    cout<< "Kare Ortasi Ayrik Dosyasindaki 500 Kisi **"<< dizi[6].islem_sayisi<<"** Islemde Bulundu."<< endl;

    for(i=0 ; i<7 ; i++){
        for(j=0 ; j<i ; j++){
            if(dizi[j].islem_sayisi<dizi[i].islem_sayisi){
                en_kisa.yontem_adi=dizi[j].yontem_adi;
                en_kisa.islem_sayisi=dizi[j].islem_sayisi;
            }
        }
    }
    return en_kisa;
}

int main(){

    srand(time(NULL));

    olustur();

    for(int i=0 ; i<500 ; i++){
        cout<< kisi[i].sira<< " "<< kisi[i].numara<< " "<< kisi[i].isim;
    }

    yontem sonuc=tarama();
    cout<< endl<< endl<<"En Hizli Yontem **"<< sonuc.yontem_adi<< "** dir ve **"<< sonuc.islem_sayisi<< "** Islemde Tamamlanmistir."<<endl;

    return 0;
}

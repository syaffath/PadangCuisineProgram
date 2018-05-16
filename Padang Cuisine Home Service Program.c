/*===================================================
	PADANG CUISINE HOME SERVICE PROGRAM DEVELOPED BY 
     	  AHMAD ZAMZAMI & SYAFIQ FATHULLAH
		DEPARTMENT OF ELECTRICAL ENGINEERING
			 UNIVERSITAS INDONESIA
=====================================================*/

//input library
#include <stdio.h> 
#include <stdlib.h> //untuk system ("cls")
#include <string.h> //untuk string
#include <conio.h> //utk getch()
//end input library

main()
{ //input data
//i = urutan, x = jumlah jenis menu, y = menu yang dipilih, n = jml. menu, tt = sub total, j = jumlah karakter yang diinput pada alamat
typedef char* string;
string nama[11]={"a","Nasi","Sayur","Sambal","Rendang","Ayam Bakar","Telur Dadar","Cincang","Perkedel","Es Teh Manis","Es Jeruk"};
string urutan[11]={"a","Pertama","Kedua","Ketiga","Keempat","Kelima","Keenam","Ketujuh","Kedelapan","Kesembilan","Kesepuluh"};
int jumlah = 0,  i, n[1000], y, x, kembali, nobeli, nomor[1000], tt[1000];
int harga[]={0,3000,2000,0,7000,7000,6000,7000,2500,3000,4000}, d[1000], tot[1000];
int nomeja=0, jmlmeja=2;
int j;
char input, input2;
char a[1], nama2[100], alamat[100], alamat2[100], notelepon[100];
double total = 0, uang;
//end input data

//input warna background
system("color 70");

i = 0, x = 0, y = 0,nobeli = 0,kembali = 0,uang = 0, total = 0;
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t        Welcome to\n \t\t\t\t\t    Padang Cuisine Home Service Program\n\n");
printf("\n\n\n\n\n\n\n\n\n\n\n\n  press any key to continue . . .");
getch();
system("cls");

//bagian utama user interface
void depan() 
{
printf("\n        Selamat Datang di RM TRIO MINANG\n\n");
printf("====================================================");
printf("\n\n                   Daftar menu");
printf("\n\n No.|        Menu       |     Harga (Rupiah)    |\n");
printf("----|-------------------|-----------------------|\n");
for(i = 1; i < 11 ; i++) {
printf("%3d |%13s      |      Rp.%5d.00      |\n", i, nama[i], harga[i]);  }
printf("====================================================\n");

//pilihan input awal
printf("\n[1] Pesan Sekarang\t\t\t[3] Bantuan\n[2] Cek Ketersediaan Tempat\t\t[4] Keluar\n\nMasukkan pilihan: ");
	scanf("%s",&input);
	printf("====================================================\n\n");
	if((input>='A'&& input<='Z')||(input>='a'&& input<='z')){
	printf("Input yang anda masukkan salah");
	printf("\n====================================================\n");
	printf("\nPress any key...");
	getch();
	system("cls");
	depan();}
	
	//bagian memilih menu
	else if (input=='1'){
		while('1'){
			do{
    			printf("Berapa jenis menu yang ingin anda pesan  : ");
   				scanf("%d", &x);
   				if(x > 10){
				printf("\nJenis menu yang anda masukkan salah! Menu hanya dari 1 sampai 10!  \n\tSilahkan Ulangi lagi!\n\n");}
			}
			while(x > 10);
			for(i = 1; i <= x ; i++)   
			{
				do
				{
					printf("\nMasukkan Nomor Menu %s : ", urutan[i]);
					scanf("%d", &d[i]);
					y = d[i];
					if (y > 10)
					{
					printf("Maaf nomor menu hanya sampai 10");
					}
				}
				while (y > 10);
		   			printf("Masukkan jumlah  : ");
	    			scanf("%d", &n[i]);
		      		y = d[i];
		      		tot[y] = n[i] * harga[y];
		   			total = tot[y] + total;
			}
			
			//bagian memilih makan dimana
			pilih:
			printf("\nMau makan dimana?");
			printf("\nTekan [1] untuk Makan di Tempat\nTekan [2] untuk Pesan Antar\n\nMasukkan pilihan: ");
			scanf("%s",&input2);
			if((input2>='A'&& input2<='Z')||(input2>='a'&& input2<='z')){
			printf("====================================================\n\n");
			printf("Input yang anda masukkan salah");
			printf("\n====================================================\n");
			goto pilih;}
	switch (input2)
   	{
	   	//makan di tempat
		case '1' :
		system("cls");
		nomeja+1, nomeja++;
		//jika meja masih tersedia
		if (nomeja<=jmlmeja)
		{
			//struk pemesanan
    		printf("\nRincian Pesanan Anda    :  \n");
			printf("\nNomor meja: %d\n", nomeja);
			printf("==================================================================================");
			printf("\n No.|        Menu       |     Harga (Rupiah)    |  Jumlah  |       Subtotal      |\n");
			printf("----|-------------------|-----------------------|----------|---------------------|\n");
			for(i = 1; i <= x ; i++)   
			{
				y = d[i];
				tt[i] = n[i] * harga[y];
				nobeli = d[i];
				printf("%3d |  %13s    |      Rp.%5d.00      | %5d    |     Rp. %5d.00\t |\n",i,  nama[nobeli], harga[nobeli],n[i], tt[i]);
			}
			printf("==================================================================================\n");
			printf("\n");
			printf("Total pesanan anda        : Rp. %.2lf\n\n", total);
			
			
			
			do
			{
				printf("Masukkan uang anda        : Rp. ");
				scanf("%lf", &uang);
				if (uang < total)
				
				{
					printf("\a\n\tMaaf uang anda kurang silahkan ulangi proses transaksi!!\n \t Silahkan masukkan lagi uang anda!\n\n");
				}
				else
				{
					continue;
				}
			
			}
			while (uang < total);
			kembali = uang - total;
			printf("\nKembalian anda            : Rp. %d.00", kembali);
			printf("\n\n\n                                   Selamat Menikmati              \n");
			printf("\n                    Terima Kasih Telah Berkunjung ke RM TRIO MINANG              \n");
			printf("\n                                 Sampai Jumpa Kembali              \n");
			printf("\n_______________________________________________________________________________\n\n");
			printf("\nPress any key...");
			getch();
			system("cls"); depan(); break;
		}
		//ketika meja sudah dipesan semua
		else
		printf("===================================================\n");
		printf("\tMohon Maaf Semua Meja Telah Dipesan\n\t   Silahkan Datang Kembali Nanti\n\t\t   Terimakasih\n");
		printf("===================================================\n");
		printf("\nPress any key...");
		getch();
		system("cls"); depan(); break;
   		break;
   	
   		//bagian pesan antar dan alamat kirim
	   	case '2' :
	   	system("cls");
	   	if (total>=15000 && total<=1000000)
		{
			//print struk pemesanan
	    	printf("\nRincian Pesanan Anda    :  \n");
			printf("==================================================================================");
			printf("\n No.|        Menu       |     Harga (Rupiah)    |  Jumlah  |       Subtotal      |\n");
			printf("----|-------------------|-----------------------|----------|---------------------|\n");
			for(i = 1; i <= x ; i++)   
			{
				y = d[i];
				tt[i] = n[i] * harga[y];
				nobeli = d[i];
				printf("%3d |  %13s    |      Rp.%5d.00      | %5d    |     Rp. %5d.00\t |\n",i,  nama[nobeli], harga[nobeli],n[i], tt[i]);
			}
			printf("==================================================================================\n");
			printf("\n");
			printf("Ongkos kirim              : Gratis\n");
			printf("Total pesanan anda        : Rp. %.2lf\n\n", total); 
			printf("Masukkan alamat anda\n");
			printf("\tNama        : ");
			gets(a);
			gets(nama2);
			printf("\tNo. Telepon : ");
			gets(notelepon);
		
			kirim:
			printf("\tAlamat      : ");
			gets(alamat);
			//merubah alamat jd lowercase
			for(j=0;j<=strlen(alamat);j++)
  			{
	    	if(alamat[j]>=65 && alamat[j]<=92)
	    	{
			alamat[j]=alamat[j]+32;
	    	}
 			}
			//bagian penyaring alamat
			if (strstr(alamat, "depok"))
			{
				printf("\n\n\n                      Terima Kasih, %s              \n", nama2);
				printf("\n                     Pesanan Anda Akan Segera Tiba              \n");
				printf("\n                           Selamat Menikmati              \n");
				printf("\n_______________________________________________________________________________\n\n");			printf("\nPress any key...");
				getch();
				system("cls"); depan(); break;
			}
		
			else if (strstr(alamat, "beji"))
			{
				printf("\n\n\n                      Terima Kasih, %s              \n", nama2);
				printf("\n                     Pesanan Anda Akan Segera Tiba              \n");
				printf("\n                           Selamat Menikmati              \n");
				printf("\n_______________________________________________________________________________\n\n");
				printf("\nPress any key...");
				getch();
				system("cls"); depan(); break;
			}
	
			else if (strstr(alamat, "kukusan"))
			{
				printf("\n\n\n                      Terima Kasih, %s              \n", nama2);
				printf("\n                     Pesanan Anda Akan Segera Tiba              \n");
				printf("\n                           Selamat Menikmati              \n");
				printf("\n_______________________________________________________________________________\n\n");
				printf("\nPress any key...");
				getch();
				system("cls"); depan(); break;
			}
		
			else if (strstr(alamat, "pondok cina"))
			{
				printf("\n\n\n                      Terima Kasih, %s              \n", nama2);
				printf("\n                     Pesanan Anda Akan Segera Tiba              \n");
				printf("\n                           Selamat Menikmati              \n");
				printf("\n_______________________________________________________________________________\n\n");
				printf("\nPress any key...");
				getch();
				system("cls"); depan(); break;
			}
		
			else if (strstr(alamat, "kemiri muka"))
			{
				printf("\n\n\n                      Terima Kasih, %s              \n", nama2);
				printf("\n                     Pesanan Anda Akan Segera Tiba              \n");
				printf("\n                           Selamat Menikmati              \n");
				printf("\n_______________________________________________________________________________\n\n");
				printf("\nPress any key...");
				getch();
				system("cls"); depan(); break;
			}
		
			else if (strstr(alamat, "tanah baru"))
			{
				printf("\n\n\n                      Terima Kasih, %s              \n", nama2);
				printf("\n                     Pesanan Anda Akan Segera Tiba              \n");
				printf("\n                           Selamat Menikmati              \n");
				printf("\n_______________________________________________________________________________\n\n");
				printf("\nPress any key...");
				getch();
				system("cls"); depan(); break;
			}
		
			else if (strstr(alamat, "srengseng sawah"))
			{
				printf("\n\n\n                      Terima Kasih, %s              \n", nama2);
				printf("\n                     Pesanan Anda Akan Segera Tiba              \n");
				printf("\n                           Selamat Menikmati              \n");
				printf("\n_______________________________________________________________________________\n\n");
				printf("\nPress any key...");
				getch();
				system("cls"); depan(); break;
			}
		
			else
			{
				printf("============================================================\n");
				printf("\tMohon Maaf Alamat Anda Diluar Jangkauan Kami\n\t   Silahkan Pilih Alamat Lain\n");
				printf("============================================================\n");
				goto kirim;
			}
	

		}
		else if(total<15000)
		{
			printf("===================================================\n");
			printf("\tPesanan Anda Kurang dari Rp. 15000.00\n\t       Silahkan Pesan Kembali\n");
			printf("===================================================\n");
			printf("\nPress any key...");
			getch();
			system("cls"); depan(); break;
		}
		else
		{
			printf("===================================================\n");
			printf("\tPesanan Anda Lebih dari Rp. 1.000.000.00\n\t       Silahkan Pesan Kembali\n");
			printf("===================================================\n");
			printf("\nPress any key...");
			getch();
			system("cls"); depan(); break;
		}

	   	break;
		default:
		printf("====================================================\n\n");
	   	printf("Input yang anda masukkan salah!");
	   	printf("\nPress any key...");
		getch();
		system("cls"); depan(); break;
	   	break;
	}
			}
			 }
	//end of menu 1
	
	//menampilkan jml.tempat yg tersedia
	else if(input=='2')
	{
		system("cls");
		if (jmlmeja-nomeja>=0)
		printf("\n**Tempat yang tersedia: %d meja**\n\n\n", jmlmeja-nomeja);
		else
		printf("\n**Tempat yang tersedia: 0 meja**\n\n\n");
		depan();
	}
	//menu help
	else if(input=='3')
	{
		system("cls");
		printf("*Petunjuk pemesanan*\nTekan 1 untuk memesan.\nKemudian pilih berapa jenis menu yang ingin dipesan.\nTuliskan nomor menu yang ingin dipesan.\nMasukkan jumlah pesanan pada tiap menu.\nBayar pesanan sesuai tagihan.\n*Perhatian!*\nUntuk layanan pesan antar minimal pembelian Rp. 15000.00\n\n\n");
		depan();
	}
	//menu exit
	else if(input=='4')
	{
		printf("\n  Terima Kasih Telah Berkunjung ke RM TRIO MINANG              \n");
		printf("\n               Sampai Jumpa Kembali              \n");
		printf("\n____________________________________________________\n\n\n");
		printf("Dikembangkan oleh AhmadZ & syaffath");
		printf("\nPress any key to exit...");
		getch();
		exit(0);
	}
	else
	{
		printf("Input yang anda masukkan salah");
		printf("\nPress any key...");
		getch();
		system("cls");
		depan();
	}
}
	
	depan();

}

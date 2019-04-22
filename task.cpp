/*
Kamu adalah seorang programmer di ASUX COMPANY. Atasan memerintahkan mu untuk membuat sebuah program yang dapat meng-entry jam kerja dan gaji dari freelance dan karyawan tetap (employee) serta dapat menampilkan data yang sudah ada. Buatlah aplikasi tersebut dengan ketentuan sebagai berikut :
	Program menampilkan menu utama yang berisi :
1.Insert Freelance
2.View Freelance
3.Insert Employee
4.View Employee
5.Exit
	Jika user memilih “Insert Freelance” (tekan tombol ‘1’),maka program akan: 
Meminta user memasukkan nama dan lama kerja dari freelance.
•	Meminta user memasukkan nama. Validasikan panjang nama harus antara 5 sampai 25 karakter.
•	Meminta user memasukan lama kerja dari freelance. Validasikan lama kerja antara 3 sampai 5 jam.
•	Hitung gaji dari freelance dengan rumus : 
gaji = jam kerja * 10000 
•	Jika berhasil, tampilkan pesan “Success insert new freelance”.
•	Validasikan jumlah maksimal freelance yang dapatdientry adalah sebanyak 5 orang.

	Jika user memilih “View Freelance” (tekan tombol ‘2’), maka program akan: 
•	Menampilkan list freelance yang telah ada. Validasikan freelance harus telah ada sebelumnya. Jika tidak, tampilkan pesan “There is no freelance to be shown”.

	Jika user memilih “Insert Employee” (tekan tombol ‘3’), maka program akan meminta user memasukkan nama dan lama jam lembur dari employee. Jam kerja dari employee adalah 8 jam perhari.
•	Meminta user memasukan nama. Validasikan panjang nama harus antara 5 sampai 25 huruf.
•	Validasikan lama jam lembur antara 3 sampai 5 jam.
•	Hitung gaji dari employee dengan rumus : 
gaji = gaji per hari + upah lembur
gaji per hari = jam kerja * 20000
upah lembur = jam lembur * 30000
•	Jika berhasil, tampilkan pesan “Success insert new employee”.
•	Validasikan jumlah maksimal employee yang dapatdientry adalah sebanyak 5 orang.

	Jika user memilih “View Employee” (tekantombol ‘4’), maka program akan
•	Menampilkan list employee yang telah ada. Validasikan employee harus telah ada sebelumnya. Jika tidak, tampilkan pesan “There is no employee to be shown”. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
protected:
    string nama;
    int gajiTot, jam, lembur;

    public:
    	Employee(int gajiTot=0, int jam=8, int lembur=0):gajiTot(),jam(8),lembur(){}
        //Employee(){jam = 8;};
        void hitungGaji(){
        	if (lembur == 0)
        	{
        		gajiTot = jam * 20000;
        	}
        	int gaji = jam * 20000;
        	gajiTot = lembur * 30000 + gaji;
            
        };
        void putNama(string const &ya){nama = ya;};
        void putLembur(int gitu){lembur = gitu;};
        string getNama(){return nama;};
        int getGaji(){return gajiTot;};
        int getJam(){return jam;};
        int getLembur(){return lembur;};
};

class Freelancer : public Employee{
public:
	Freelancer(int masih=0, int missqueen=0, int aja=0): Employee(masih, missqueen, aja){}
	void putJam(int missqueen){jam = missqueen;};
};

void terserah(vector<Freelancer> &apaaja){
	Freelancer freelance; string nama; int jam=0;
	size_t a = 5;
    if( apaaja.size() >= a)
	{
		string pusink;
		cout<<string(70, '\n');
		cout<<"There is no slot for freelance for now.."<<endl;
		cout<<"Do you want to dismiss someone? Input the freelance's name : "; cin>>pusink;
		
		/*if(find_if(apaaja.begin(), apaaja.end(), pusink) != apaaja.end()) {
    		cout<<"ketemu"<<endl;
		} else {
    		cout<<"TThere is no freelance with that name..."<<endl;
		}

		/*auto it = find(apaaja.begin(), apaaja.end(), Freelancer("adeqecil"));
   		if (it != apaaja.end()) {
      		auto idx = distance(apaaja.begin(), it);
      		cout << "b= " << it->Getb() << " c= " << it->Getc() << endl;
      		cout << "Index= " << idx << endl;
    	} else
      cout << "CC is not found" << endl;*/
	}
	else{
		cout<<string(70, '\n');
    	while(nama.size() < 5 || nama.size() > 25){
    		cout<<"\nInput Freelancer's name [5-25] : "; cin>>nama;
    	};freelance.putNama(nama);
    	while(jam < 3 || jam > 5){
    		cout<<"\nWork Hour [3-5]: ";cin>>jam;
    	};freelance.putJam(jam);
    	freelance.hitungGaji(); //calc salary
    	apaaja.push_back(freelance); //push the object

    	cout<<"\n\nSuccess insert new freelancer!"<<endl;
    }
    cin.get();
}

void aja(vector<Freelancer> &gatau){
	cout<<string(70, '\n');
	size_t a = 0;
	if (gatau.size() == a)
	{
		cout<<"There is no freelance to be shown"<<endl;
	}
	else{
    	cout<<"FREELANCER LIST"<<endl;
    	for (int i = 0; i < gatau.size(); i++)
    	{
        	cout<<'\n'<<i+1<<".Name\t\t: "<<gatau[i].getNama()<<endl;
        	cout<<" Work Hour\t: "<< gatau[i].getJam()<<endl;
        	cout<<" Salary\t\t: "<<gatau[i].getGaji()<<endl;
    	}
	}
    cin.get();
    
}

void aku(vector<Employee> &gatau){
    //<blabla_code> this line should create new object for this new user input
    ;
    Employee karyawan; string nama; int lembur;
    size_t a = 5;
    if( gatau.size() >= a)
	{
		cout<<string(70, '\n');
		cout<<"There is no slot for employee for now.."<<endl;
		
	}
	else{
    	cout<<string(70, '\n');
    	while(nama.size() < 5 || nama.size() > 25){
    		cout<<"\nInput Employee's name [5-25] : "; cin>>nama;
    	};karyawan.putNama(nama);
    	cout<<"\nWork Hour : "<<karyawan.getJam()<<endl;
    	while(lembur < 0 || lembur > 4){
    		cout<<"\nInput overtime's duration [0 - 4] : ";
    		cin>>lembur;
    	};
    	karyawan.putLembur(lembur);
    	karyawan.hitungGaji(); //calc salary
    	gatau.push_back(karyawan); //push the object

    	cout<<"\n\nSuccess insert new employee!"<<endl;
	}
    cin.get();
}

void bingung(vector<Employee> &gatau){
	cout<<string(70, '\n');
	size_t a = 0;
	if (gatau.size() == a)
	{
		cout<<"There is no employee to be shown"<<endl;
	}
	else{
    	cout<<"EMPLOYEE LIST"<<endl;
    	for (int i = 0; i < gatau.size(); i++)
    	{
        	cout<<'\n'<<i+1<<".Name\t\t: "<<gatau[i].getNama()<<endl;
        	cout<<" Work Hour\t: "<< gatau[i].getJam()<<endl;
        	cout<<" Overtime Hour\t: "<<gatau[i].getLembur()<<endl;
        	cout<<" Salary\t\t: "<<gatau[i].getGaji()<<endl;
    	}
    }
    cin.get();
    
}

int Layout(vector<Employee> &kamuFree, vector<Freelancer> &akuFree){
    int choice = 0;
    while(choice != 5){
    do{
        cout<<string(70, '\n')<<"adeqecil COMPANY"<<endl;
        cout<<string(16, '=')<<endl;
        cout<<"1.Insert Freelance"<<endl;
        cout<<"2.View Freelance"<<endl;
        cout<<"3.Insert Employee"<<endl;
        cout<<"4.View Employee"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Input choice : "; cin>>choice;
    } while(choice <1 && choice >5 && !cin);

    switch (choice)
    {
        case 1:
        	terserah(akuFree);
       		cin.get();
        	break;
        case 2:
        	aja(akuFree);
        	cin.get();
        	break;
        case 3: 
            aku(kamuFree);
            cin.get();
            break;
    
        case 4:
            bingung(kamuFree);
            cin.get();
            break;
    }
}
    return 0;
}

int main(){
    vector<Employee> kamuFree;
    vector<Freelancer> akuFree;
    Layout(kamuFree, akuFree);
    cin.get();
    return 0;
}
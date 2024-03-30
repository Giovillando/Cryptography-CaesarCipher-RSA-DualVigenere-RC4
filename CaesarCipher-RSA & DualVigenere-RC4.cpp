#include <iostream>
#include <cmath>
#include <algorithm>
#include<cstdlib>
#include<winsock.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int p, q,n,d,e,g,f,p1,q1,e1,d1,shift;
string asdf,plaintext,plaintext1,kc;
char message[100];
// Fungsi untuk mencari nilai gcd (greatest common divisor) dari dua bilangan

void leftrotate(string &s, int d)
{
reverse(s.begin(), s.begin()+d);
reverse(s.begin()+d, s.end());
reverse(s.begin(), s.end());
}

void rightrotate(string &s, int d)
{
leftrotate(s, s.length()-d);
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Fungsi untuk mencari nilai modulo dengan menggunakan algoritma eksponensial cepat
int mod(int base, int exponent, int modulus)
{
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

// Fungsi untuk mencari nilai e yang cocok untuk kunci publik
int findE(int phi) {
    int e = 2;
    while (e < phi)
	{
        if (gcd(e, phi) == 1) return e;
        e++;
    }
    return 1;
}

// Fungsi untuk mencari nilai d yang cocok untuk kunci privat
int findD(int e, int phi) {
    int d = 1;
    while (d < phi) {
        if ((d * e) % phi == 1) return d;
        d++;
    }
    return 0;
}

// Fungsi untuk mengenkripsi pesan dengan menggunakan kunci publik
string encrypt(int e, int n, string ciphertext) {
    string encryptedMessage = "";
    for (char c : ciphertext) {
        int x = (int)c;
        int y = mod(x, e, n);
        encryptedMessage += to_string(y) + " ";
    }
    return encryptedMessage;
}

string encrypt1(int e, int n, string ciphertext)
{
    string encryptedMessage1 = "";
    for (char c : ciphertext) {
        int x = (int)c;
        int y = mod(x, e, n);
        encryptedMessage1 += to_string(y) + "";
    }
    return encryptedMessage1;
}

string caesar(string plaintext1, int key)
{
    string output;

    for (char c : plaintext1)
    {
        if (c >= 'a' && c <= 'm')
        {
            output += (c + key);
        }
        else if (c >= 'n' && c <= 'z')
        {
            output += (c - key);
        }
        else if (c >= 'A' && c <= 'M')
        {
            output += (c + key);
        }
        else if (c >= 'N' && c <= 'Z')
        {
            output += (c - key);
        }
        else
        {
            output += c;
        }
    }

    return output;
}

string rot13(const string& input)
{
    string output;

    for (char c : input)
    {
        if (c >= 'a' && c <= 'm')
        {
            output += (c + 13);
        }
        else if (c >= 'n' && c <= 'z')
        {
            output += (c - 13);
        }
        else if (c >= 'A' && c <= 'M')
        {
            output += (c + 13);
        }
        else if (c >= 'N' && c <= 'Z')
        {
            output += (c - 13);
        }
        else
        {
            output += c;
        }
    }

    return output;
}

string caesar_cipher(const string& text, int shift) {

    string result = "";
	// traverse text
	for (int i=0;i<text.length();i++)
	{
		// ubah masing masing karakter
		// huruf kapital
		if (isupper(text[i]))
			result += char(int(text[i]+shift-65)%26 +65);
	// bukan huruf kapital
	else
		result += char(int(text[i]+shift-97)%26 +97);
	}
	// return hasil enkripsi
	return result;
}

// Fungsi untuk mendekripsi pesan dengan menggunakan kunci privat

void displayASCII(const string& message, vector<int>& asciiValues) {
    for (char ch : message) {
        int asciiValue = static_cast<int>(ch);
        asciiValues.push_back(asciiValue);
    }
}


void tampilkanTabel(const vector<int>& angka_ascii) {
    for (int angka : angka_ascii) {
        char karakter = static_cast<char>(angka);
        cout << karakter;
    }
}

int stringToInteger(const string& str) {
    int result = 0;
    for (char digit : str) {
        if (isdigit(digit)) {
            result = result * 10 + (digit - '0');
        } else {
            cerr << "Error: Non-numeric character found in input." << endl;
            exit(1);
        }
    }
    return result;
}

int enkripsi_kunci()
{
    //enkripsi menggunakan algoritma RSA
    string str2,str3,str4,str5,str7, a,ciphertext1, ciphertext,decrypted,decrypted1,encryptedOneTimePad,text,b,kunci="",kuncibaru="",rev="",dekrip;
    char input[64], rev_str[64], kunciascii; unsigned char * plaintextrc4;
    unsigned char * kuncirc4;unsigned char * kuncirc42;  unsigned char * enkripsirc4;unsigned char * enkripsirc42;
    unsigned char * dekripsirc4;unsigned char * dekripsirc42;
    char key2[100],message2[100],ch,ch1;
	int k,j,key,jj;
	cout<<"  ***********************ENKRIPSI KUNCI********************"<<endl;
    // Nilai p dan q yang akan digunakan untuk menghasilkan kunci publik dan privat

    //RSA
    cout<<"\tMasukkan Plaintext Kunci  :";
	cin>>str2;
    // Menghitung nilai n dan phi
    plaintext1=str2;
cout<<"\tMasukkan pergeseran       :";
	cin>>k;
    rightrotate(plaintext1,k);

    cout<<"\tPlaintext Right Shift K   : " <<plaintext1<<endl;
    cout<<"\tMasukkan Kunci caesar   :";
    cin>>kc;
    vector<int> asciiValues;

    // Menampilkan semua nilai ASCII dari pesan
    displayASCII(kc, asciiValues);

    int sum = 0;
    int count = 0;

    // Menampilkan semua nilai ASCII
    cout << "ASCII Values: ";
    for (int value : asciiValues) {
        cout << value << " ";
        int asciiValue = static_cast<int>(value);
        if (asciiValue % 2 == 0) {  // Check jika bilangan genap
            sum += asciiValue;
            count++;
        }
    }
    if (count == 0) {
        cerr << "Tidak ada bilangan genap dalam string." << endl;
        return -1; // Menandakan kesalahan
    }

// Iterasi melalui setiap karakter dalam string
// Inisialisasi variabel untuk menghitung jumlah ASCII dan jumlah karakter


// Hitung rata-rata ASCII dengan membagi sum dengan jumlah karakter
int rounded_average = (double)sum / count;

// Pembulatan rata-rata ASCII ke atas atau ke bawah

cout<<endl;
// Cetak hasil
cout << "\tRata-rata ASCII string Genap yang dibulatkan adalah: " << rounded_average << endl;

    string encrypted1 = caesar_cipher(plaintext1, rounded_average);
    cout << " Hasil Enkripsi Caesar Cipher: " << encrypted1 << endl;

    cout<<"\tMasukkan Prima Pertama    :";
    cin>>p;
    cout<<"\tMasukkan Prima Kedua      :";
    cin>>q;

    n = p * q;
    int phi = (p - 1) * (q - 1);
    // Mencari nilai e yang cocok untuk kunci publik
    e = findE(phi);
    cout<<"Nilai e (euler) : "<<e<<endl;
    // Mencari nilai d yang cocok untuk kunci privat
    d = findD(e, phi);
    // Pesan yang akan dienkripsi

    string encryptedMessage = encrypt(e, n, encrypted1);
    string encryptedMessage1 = encrypt1(e, n, encrypted1);
    cout <<"\tHasil Kunci Privat (d)      : " <<d<< endl;
    cout <<"\tHasil Enkripsi Kunci     : " << encryptedMessage << endl;

    cout <<"\tKunci Pesan              : " << encryptedMessage1 << endl;

    // Mendefinisikan string encryptedMessage

    // Mengonversi string menjadi vektor angka ASCII
    vector<int> angka_ascii;
    size_t pos = 0;
    while ((pos = encryptedMessage.find(" ")) != string::npos) {
        angka_ascii.push_back(stringToInteger(encryptedMessage.substr(0, pos)));
        encryptedMessage.erase(0, pos + 1);
    }
    angka_ascii.push_back(stringToInteger(encryptedMessage));

    // Menampilkan hasil konversi
    cout<<"Hasil Enkripsi dalam bentuk char : ";
    tampilkanTabel(angka_ascii);

    cout << endl;

    return 0;
}

string sortString(string plaintextvgg) {
    int N = plaintextvgg.length();
    vector<int> freq(256, 0);

    for (int i = 0; i < N; i++) {
        freq[plaintextvgg[i]]++;
    }

    plaintextvgg = "";
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < freq[i]; j++)
            plaintextvgg = plaintextvgg + (char)i;
    }

    return plaintextvgg;
}

class Vigenere {
public:
    string kunci;
    Vigenere(string kunci) {
        for(int i = 0; i < kunci.size(); ++i) {
            if (kunci[i] >= 'A' && kunci[i] <= 'Z') {
                this->kunci += kunci[i];
            } else if (kunci[i] >= 'a' && kunci[i] <= 'z') {
               this->kunci += kunci[i] + 'A' - 'a';
            }
        }
    }


string enkripsiVG(string text) {
    string out1;
    for (int i = 0, j = 0; i < text.length(); ++i) {
        char c = text[i];
        if (c >= 'a' && c<= 'z') {
            c += 'A' - 'a';
        } else if ( c < 'A' || c> 'Z') {
            continue;
        }
        out1 += (c + kunci[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % kunci.length();
        }
        return out1;
    }

string dekripsiVG(string text) {
        string out;
        for (int i = 0, j = 0; i < text.length(); ++i) {
            char c = text[i];
            if (c >= 'a' && c<= 'z') {
                c += 'A' - 'a';
            } else if ( c < 'A' || c> 'Z') {
                continue;
            }
            out += (c - kunci[j] + 26) % 26 + 'A';
            j = (j + 1) % kunci.length();
        }
        return out;
    }
};

string RC4(string str2, string str3)
{
    // Inisialisasi variabel
    int S[256], T[256];
    for (int i = 0; i < 256; i++)
        S[i] = i;
    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + str3[i % str3.length()]) % 256;
        swap(S[i], S[j]);
    }
    int i = 0, k = 0;
    string hasil_enkripsi = "";
    for (int n = 0; n < str2.length(); n++)
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        k = S[(S[i] + S[j]) % 256];
        hasil_enkripsi += char(k ^ str2[n]);
    }
    return hasil_enkripsi;
}

string encript(string pesan_enkripsi, string str3)
{
    // Create a result string the same size as the message
    string result(pesan_enkripsi.size(), ' ');

    // Loop through each character in the message
    for (int i = 0; i < pesan_enkripsi.size(); i++)
        {
        // Encrypt each character by XORing it with the corresponding character in the key
        result[i] = pesan_enkripsi[i] ^ str3[i];
    }

    return result;
}

string encript1(string ciphertext1, string str3)
{
    // Create a result string the same size as the message
    string result(ciphertext1.size(), ' ');
    // Loop through each character in the message
    for (int i = 0; i < ciphertext1.size(); i++)
        {
        // Encrypt each character by XORing it with the corresponding character in the key
        result[i] = ciphertext1[i] ^ str3[i];
    }

    return result;
}


int enkripsi_pesan()
{
    cout<<"  ***********************ENKRIPSI PESAN********************"<<endl;
    cout<<endl;
    string str2;
    string str3,str4,str5,str7;
    string plaintextvgg,plaintextvg;
    int geser;
    cout<<"\t|\tMasukkan Plainteks Pesan Vigenere Putaran 1   : ";
	cin>>plaintextvg;
	cout<<"\t|\tMasukan Jumlah Left Shift           : " ;
    cin>>geser;
    string plaintextvg1 = plaintextvg;
    leftrotate(plaintextvg1,geser);
	cout<<"\t|\tKunci Vigenere                      : "<<plaintextvg1<<endl;
	string original = plaintextvg;
    Vigenere chiper = plaintextvg1;
    string hasilEnkripsiVG = chiper.enkripsiVG(original);
    // ALGORITMA VIGENERE
    cout<<"\t|\tHasil Enkripsi Vigenere Putaran-1   : "<<hasilEnkripsiVG<<endl;
     cout << "Masukkan Plainteks Pesan Vigenere Putaran 2   : ";
    cin>>plaintextvgg;
    for (int i = 0; i < plaintextvgg.length(); i++) {
        int vgg = (int)plaintextvgg[i];
        cout << " - Desimal ASCII dari " << plaintextvgg[i] << " : " << (int)plaintextvgg[i] << endl;
    }
    string a = sortString(plaintextvgg);
    cout << "Kunci Vigenere (hasil sort ASCII)   : " << a << endl;
    string original1 = plaintextvgg;
    Vigenere chiper1 = a;
    string hasilEnkripsiVG1 = chiper1.enkripsiVG(original1);
    cout << "Hasil Enkripsi Vigenere Putaran-2    : " << hasilEnkripsiVG1 << endl;
    cout<<"\tMasukkan Kunci Hasil Dari RSA DAN Caesar Cipher           : ";
   cin>>str3;
string pesan_enkripsi = RC4(hasilEnkripsiVG1, str3);
cout<<"\tHasil Enkripsi RC4: " <<pesan_enkripsi<<endl;
string ciphertext1=encript1(pesan_enkripsi, str3);
cout<<"\tHasil Enkripsi Pesan: "<<ciphertext1<<endl;
cout<<endl;
}

string decript(string str4, string str5)
{
    // Decryption is the same as encryption, just XORing the ciphertext with the key
    return encript(str4, str5);
}

string RC4_decrypt(string decrypted1, string str5)
{
    // Inisialisasi variabel
    int S[256], T[256];
    for (int i = 0; i < 256; i++)
        S[i] = i;
    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + str5[i % str5.length()]) % 256;
        swap(S[i], S[j]);
    }
    int i = 0, k = 0;
    string hasil_dekripsi = "";
    for (int n = 0; n < decrypted1.length(); n++)
    {
        i = (i + 1) % 256;

        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        k = S[(S[i] + S[j]) % 256];
        hasil_dekripsi += char(k ^ decrypted1[n]);
    }
    return hasil_dekripsi;
}


int dekripsi_pesan()
{
string str2,str3,str4,str5,str7, a,ciphertext1, ciphertext,decrypted,decrypted1,encryptedOneTimePad,text,b,kunci="",kuncibaru="",rev="",dekrip,ciphertextvg,ciphertextvg1,ciphertextvgg,ciphertextvg2;
char input[64], rev_str[64], kunciascii; unsigned char * plaintextrc4;
unsigned char * kuncirc4;unsigned char * kuncirc42;  unsigned char * enkripsirc4;unsigned char * enkripsirc42;
unsigned char * dekripsirc4;unsigned char * dekripsirc42;
char key2[100];
cout<<"  ***********************DEKRIPSI PESAN********************"<<endl;
cout<<"\tMasukkan Hasil enkripsi RC4        : ";
cin>>str4;
cout<<"\tMasukkan Kunci Hasil Dari RSA DAN Caesar Cipher            : ";
cin>>str5;
decrypted1= decript(str4, str5);
cout<<"\tDekripsi RC4                   : "<<decrypted1<<endl;
string pesan_dekripsi = RC4_decrypt(decrypted1, str5);
cout<<"\t Hasil Dekripsi Pesan (Plaintext Pesan) : "<<pesan_dekripsi<<endl;

cout<<"\t|\tMasukkan Ciphertext Pesan Vigenere  : ";
	cin>>ciphertextvg;
	cout<<"\t|\tMasukan Kunci Vigenere              : " ;
    cin>>ciphertextvg1;
	string original = ciphertextvg;
    Vigenere chiper = ciphertextvg1;
    string hasilDekripsiVG = chiper.dekripsiVG(original);
    cout<<"\tHasil Enkripsi Vigenere Putaran-2   : "<<hasilDekripsiVG<<endl;
    cout<<"\t|\tMasukkan Ciphertext Pesan Vigenere  : ";
	cin>>ciphertextvgg;
	cout<<"\t|\tMasukan Kunci Vigenere              : " ;
    cin>>ciphertextvg2;
	string original2 = ciphertextvgg;
    Vigenere chiper2 = ciphertextvg2;
    string hasilDekripsiVG2 = chiper2.dekripsiVG(original2);
    cout<<"\t|********************************************************************************************|"<<endl;
	cout<<"\t|\tHasil Enkripsi Vigenere Putaran-1   : "<<hasilDekripsiVG2<<endl;
cout<<endl;
cout<<"  *************************************************************"<<endl;
}

string decrypt(int d1, int n, string encryptedMessage)
{
	encryptedMessage+=" ";
    string decryptedMessage = "";
    string number = "";
    for (char c : encryptedMessage)
	{
        if (c == ' ') {
            int x = stoi(number);
            int y = mod(x, d1, n);
            char z = (char)y;
            decryptedMessage += z;
            number = "";
        }
        else {
            number += c;
        }
    }
    return decryptedMessage;
}

string decrypt_caesar(string plaintext1, int key4)
{
    string output;

    for (char c : plaintext1)
    {
        if (c >= 'a' && c <= 'm')
        {
            output += (c + key4);
        }
        else if (c >= 'n' && c <= 'z')
        {
            output += (c - key4);
        }
        else if (c >= 'A' && c <= 'M')
        {
            output += (c + key4);
        }
        else if (c >= 'N' && c <= 'Z')
        {
            output += (c - key4);
        }
        else
        {
            output += c;
        }
    }

    return output;
}

string decrypt_rot13(const string& input)
{
    string output;

    for (char c : input)
    {
        if (c >= 'a' && c <= 'm')
        {
            output += (c + 13);
        }
        else if (c >= 'n' && c <= 'z')
        {
            output += (c - 13);
        }
        else if (c >= 'A' && c <= 'M')
        {
            output += (c + 13);
        }
        else if (c >= 'N' && c <= 'Z')
        {
            output += (c - 13);
        }
        else
        {
            output += c;
        }
    }

    return output;
}

string caesar_cipher1(const string& text, int shift) {

    string result = "";
	// traverse text
	for (int i=0;i<text.length();i++)
	{
		// ubah masing masing karakter
		// huruf kapital
		if (isupper(text[i]))
			result += char(int(text[i]+shift-65)%26 +65);
	// bukan huruf kapital
	else
		result += char(int(text[i]+shift-97)%26 +97);
	}
	// return hasil enkripsi
	return result;
}

// Fungsi untuk mendekripsi pesan dengan menggunakan kunci privat

void displayASCII2(const string& message, vector<int>& asciiValues2) {
    for (char ch : message) {
        int asciiValue2 = static_cast<int>(ch);
        asciiValues2.push_back(asciiValue2);
    }
}
void displayASCII3(const string& message, vector<int>& asciiValues3) {
    for (char ch : message) {
        int asciiValue3 = static_cast<int>(ch);
        asciiValues3.push_back(asciiValue3);
    }
}

int dekripsi_kunci()
{
	int key,key1, key2, key4;
	string encryptedMessage;
	string str2,str3,str4,str5,str7,kc1, a,ciphertext1, ciphertext,decrypted,decrypted1,encryptedOneTimePad,text,b,kunci="",kuncibaru="",rev="",dekrip;
    char input[64], rev_str[64], kunciascii; unsigned char * plaintextrc4;
    unsigned char * kuncirc4;unsigned char * kuncirc42;  unsigned char * enkripsirc4;unsigned char * enkripsirc42;
    unsigned char * dekripsirc4;unsigned char * dekripsirc42;
    char message2[100],ch, ch1,ch2,ch3;
	int kk, k,j;
	cout<<endl<<endl;
	cout<<"  ******DEKRIPSI KUNCI*****"<<endl;

	//RSA
	cout<<"\tMasukkan Cipherteks: ";
	getline(cin,encryptedMessage);
	cout<<"\tMasukkan bilangan Prima 1         : ";
    cin>>p;
    cout<<"\tMasukkan bilangan Prima 2         : ";
    cin>>q;
    cout<<"\tMasukkan kunci Privat             : ";
    cin>>d1;
    cout<<"\tMasukkan Pergeseran               : ";
    cin>>key1;
    cout<<"\tMasukkan Kunci caesar             : ";
    cin>>kc1;
	n =p*q;




// Iterasi melalui setiap karakter dalam string
// Inisialisasi variabel untuk menghitung jumlah ASCII dan jumlah karakter
    vector<int> asciiValues2;

    // Menampilkan semua nilai ASCII dari pesan
    displayASCII2(kc1, asciiValues2);

    int sum = 0;
    int count = 0;

    // Menampilkan semua nilai ASCII
    cout << "ASCII Values: ";
    for (int value : asciiValues2) {
        cout << value << " ";
        int asciiValue2 = static_cast<int>(value);
        if (asciiValue2 % 2 == 0) {  // Check jika bilangan genap
            sum += asciiValue2;
            count++;
        }
    }
    if (count == 0) {
        cerr << "Tidak ada bilangan genap dalam string." << endl;
        return -1; // Menandakan k esalahan
    }

// Iterasi melalui setiap karakter dalam string
// Inisialisasi variabel untuk menghitung jumlah ASCII dan jumlah karakter


// Hitung rata-rata ASCII dengan membagi sum dengan jumlah karakter
int rounded_average = (double)sum / count;
rounded_average=rounded_average%26;

// Pembulatan rata-rata ASCII ke atas atau ke bawah

    cout<<endl;
    cout <<"\tRata-rata ASCII string yang dibulatkan adalah: " << rounded_average << endl;

    string decryptedMessage = decrypt(d1,n,encryptedMessage);
    cout<<"\tHasil Deskripsi Caesar Cipher : " <<decryptedMessage<<endl;

    string decryptedMessage1=caesar_cipher1(decryptedMessage,(26-rounded_average));
	cout<<"\tHasil Shift K : " <<decryptedMessage1<<endl;

    leftrotate(decryptedMessage1,key1);
    cout <<"\tPlaintext AWAl                   : " << decryptedMessage1 << endl;
    getch();
    exit(0);
    cout<<"  *********************"<<endl;
}


int selesai()
{
	 cout<<"  *************************************************************"<<endl;
     cout<<"                                SELESAI                        "<<endl;
     cout<<"  *************************************************************"<<endl;
}

int main(int argc, char *argv[])
{
int jawab;
menu:
     cout<<"  *************************************************************"<<endl;
     cout<<"               PROGRAM ALGORITMA RSA, OTP DAN RC4              "<<endl;
     cout<<"  *************************************************************"<<endl;
     cout<<"\t1.) Enkripsi Kunci\n";
     cout<<"\t2.) Enkripsi Pesan\n";
     cout<<"\t3.) Dekripsi Pesan\n";
     cout<<"\t4.) Dekripsi Kunci\n";
     cout<<"\t5.) Selesai\n";
     cout<<"\tSilahkan memilih menu sesuai nomor... "<<endl;
     cout<<"\tPilihan Anda:";
	 cin>>jawab;
     cin.ignore(); // mengabaikan input spasi yang terjadi ketika input jawab tadi
	switch(jawab)
	{
    case 1:
	{
		enkripsi_kunci();
		getch();
        system("cls");
        goto menu;
	}
	case 2:
    {
        enkripsi_pesan();
        getch();
        system("cls");
        goto menu;
	}
	case 3:
    {
        dekripsi_pesan();
        getch();
        system("cls");
        goto menu;
	}
	case 4:
    {
        dekripsi_kunci();
        getch();
        system("cls");
        goto menu;
	}
	case 5:
	{
		selesai();
        getch();
        system("cls");
        goto menu;
    }
	}
}

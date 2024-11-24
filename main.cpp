#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Headers
string toString(double);
int toInt(string);
double toDouble(string);
void anakLakiNo();

void anakLakiYes();

int main() {
  string anakLaki;

  cout << "Program Penghitung Harta Waris" << endl;
  cout << "Versi 1.0 -- ahli waris tersedia:" << endl;
  cout << "Suami, Istri, Bapak, Ibu, Anak laki-laki, Anak perempuan, Nenek, "
          "Kakek, Saudara laki-laki kandung, Saudara perempuan kandung"
       << endl;
  cout << "Apakah terdapat ahli waris anak laki-laki? [ya/tidak]" << endl;
  cin >> anakLaki;
  if (anakLaki == "ya") {
    anakLakiYes();
  } else {
    anakLakiNo();
  }
  return 0;
}

void anakLakiNo() {
  int i, totalHarta, hartaSisa, totalKewajiban, hartaWaris, jmlAnakperempuan,
      bykSaudara, warisKakek, biayaPemakaman;
  int hartaSuami, hartaIstri, hartaBapak, hartaIbu, hartaKakek, hartaNenek,
      hartaSaudaralaki, hartaAnakperempuan, hartaSaudaraperempuan = 0;
  int jmlSaudara[2];
  string bapak, ibu, suamiIstri, pilihanTerakhir, anakPerempuan, nenek, kakek;

  cout << "Masukkan jumlah saudara kandung dengan urutan saudara kandung "
          "laki-laki terlebih dahulu kemudian perempuan:"
       << endl;
  for (i = 0; i <= 1; i++) {
    cin >> jmlSaudara[i];
  }
  cout << "Jumlah saudara kandung laki-laki dan perempuan secara berurutan "
          "adalah "
       << jmlSaudara[0] << " dan " << jmlSaudara[1] << endl;
  bykSaudara = jmlSaudara[0] + jmlSaudara[1];
  cout << "Masukkan total harta yang ditinggalkan:" << endl;
  cin >> hartaWaris;
  cout << "Masukkan total biaya pemakaman:" << endl;
  cin >> biayaPemakaman;
  cout << "Masukkan total hutang yang ditinggalkan:" << endl;
  cin >> totalKewajiban;
  totalHarta = hartaWaris - (totalKewajiban + biayaPemakaman);
  cout << "Total harta yang siap diwariskan = Rp" << totalHarta << endl;
  cout << "Apakah terdapat ahli waris Anak Perempuan? [ya/tidak]" << endl;
  cin >> anakPerempuan;
  if (anakPerempuan == "ya") {
    cout << "Masukkan jumlah Anak Perempuan:" << endl;
    cin >> jmlAnakperempuan;
    cout << "Apakah terdapat ahli waris Bapak? [ya/tidak]" << endl;
    cin >> bapak;
    if (bapak == "ya") {
      cout << "Apakah terdapat ahli waris Ibu? [ya/tidak]" << endl;
      cin >> ibu;
      if (ibu == "ya") {
        hartaIbu = (int)((double)1 / 6 * totalHarta);
      } else {
        cout << "Apakah terdapat ahli waris Nenek? [ya/tidak]" << endl;
        cin >> nenek;
        if (nenek == "ya") {
          hartaNenek = (int)((double)1 / 6 * totalHarta);
        }
      }
      cout << "Apakah terdapat ahli waris Suami atau Istri? [suami/istri]"
           << endl;
      cin >> suamiIstri;
      if (suamiIstri == "suami") {
        hartaSuami = (int)(0.25 * totalHarta);
        cout << "Harta waris milik Suami = Rp" << hartaSuami << endl;
      } else {
        if (suamiIstri == "istri") {
          hartaIstri = (int)(0.125 * totalHarta);
          cout << "Harta waris milik Istri = Rp" << hartaIstri << endl;
        }
      }
      if (jmlAnakperempuan >= 2) {
        hartaAnakperempuan = (int)((double)2 / 3 * totalHarta);
      } else {
        hartaAnakperempuan = (int)(0.5 * totalHarta);
      }
      hartaSisa =
          totalHarta - (hartaSuami + hartaIstri + hartaBapak + hartaIbu +
                        hartaKakek + hartaNenek + hartaSaudaraperempuan);
      cout << "Harta waris milik Bapak (Asabah) = Rp" << hartaSisa << endl;
    } else {
      cout << "Apakah terdapat ahli waris Ibu? [ya/tidak]" << endl;
      cin >> ibu;
      if (ibu == "ya") {
        hartaIbu = (int)((double)1 / 6 * totalHarta);
      } else {
        cout << "Apakah terdapat ahli waris Nenek? [ya/tidak]" << endl;
        cin >> nenek;
        if (nenek == "ya") {
          hartaNenek = (int)((double)1 / 6 * totalHarta);
        }
      }
      cout << "Apakah terdapat ahli waris Suami atau Istri? [suami/istri]"
           << endl;
      cin >> suamiIstri;
      cout << "Apakah terdapat ahli waris Kakek? [ya/tidak]" << endl;
      cin >> kakek;
      if (jmlSaudara[1] == 1) {
        hartaSaudaraperempuan = (int)(0.5 * totalHarta);
      } else {
        if (jmlSaudara[1] > 0) {
          hartaSaudaraperempuan =
              (int)((double)2 / 3 * totalHarta / jmlSaudara[1]);
        }
      }
      if (suamiIstri == "suami") {
        hartaSuami = (int)(0.25 * totalHarta);
        cout << "Harta waris milik Suami = Rp" << hartaSuami << endl;
      } else {
        if (suamiIstri == "istri") {
          hartaIstri = (int)(0.125 * totalHarta);
          cout << "Harta waris milik Istri = Rp" << hartaIstri << endl;
        }
      }
      if (kakek == "ya") {
        hartaKakek = (int)((double)1 / 6 * totalHarta);
        hartaSisa =
            totalHarta - (hartaSuami + hartaIstri + hartaBapak + hartaIbu +
                          hartaKakek + hartaNenek + hartaSaudaraperempuan);
        warisKakek = hartaKakek + hartaSisa;
        cout << "Harta waris milik Kakek (1/6 + Asabah) = Rp" << warisKakek
             << endl;
      }
      if (jmlAnakperempuan >= 2) {
        hartaAnakperempuan = (int)((double)2 / 3 * totalHarta);
      } else {
        hartaAnakperempuan = (int)(0.5 * totalHarta);
      }
    }
    cout << "Harta waris milik Anak Perempuan = Rp" << hartaAnakperempuan
         << endl;
  } else {
    cout << "Apakah terdapat ahli waris Bapak? [ya/tidak]" << endl;
    cin >> bapak;
    if (bapak == "ya") {
      cout << "Apakah terdapat ahli waris Ibu? [ya/tidak]" << endl;
      cin >> ibu;
      if (ibu == "ya") {
        if (bykSaudara >= 2) {
          hartaIbu = (int)((double)1 / 6 * totalHarta);
        } else {
          hartaIbu = (int)((double)1 / 3 * totalHarta);
        }
      } else {
        cout << "Apakah terdapat ahli waris Nenek? [ya/tidak]" << endl;
        cin >> nenek;
        if (nenek == "ya") {
          hartaNenek = (int)((double)1 / 6 * totalHarta);
        }
      }
      if (jmlSaudara[1] == 1) {
        hartaSaudaraperempuan = (int)(0.5 * totalHarta);
      } else {
        if (jmlSaudara[1] > 0) {
          hartaSaudaraperempuan =
              (int)((double)2 / 3 * totalHarta / jmlSaudara[1]);
        }
      }
      cout << "Apakah terdapat ahli waris Suami atau Istri? [suami/istri]"
           << endl;
      cin >> suamiIstri;
      if (suamiIstri == "suami") {
        hartaSuami = (int)(0.5 * totalHarta);
        cout << "Harta waris milik Suami = Rp" << hartaSuami << endl;
      } else {
        if (suamiIstri == "istri") {
          hartaIstri = (int)(0.25 * totalHarta);
          cout << "Harta waris milik Istri = Rp" << hartaIstri << endl;
        }
      }
      hartaSisa =
          totalHarta - (hartaSuami + hartaIstri + hartaBapak + hartaIbu +
                        hartaKakek + hartaNenek + hartaSaudaraperempuan);
      cout << "Harta waris milik Bapak (Asabah) = Rp" << hartaSisa << endl;
    } else {
      cout << "Apakah terdapat ahli waris Ibu? [ya/tidak]" << endl;
      cin >> ibu;
      if (ibu == "ya") {
        if (bykSaudara >= 2) {
          hartaIbu = (int)((double)1 / 6 * totalHarta);
        } else {
          hartaIbu = (int)((double)1 / 3 * totalHarta);
        }
      } else {
        cout << "Apakah terdapat ahli waris Nenek? [ya/tidak]" << endl;
        cin >> nenek;
        if (nenek == "ya") {
          hartaNenek = (int)((double)1 / 6 * totalHarta);
        }
      }
      if (jmlSaudara[1] == 1) {
        hartaSaudaraperempuan = (int)(0.5 * totalHarta);
      } else {
        if (jmlSaudara[1] > 0) {
          hartaSaudaraperempuan =
              (int)((double)2 / 3 * totalHarta / jmlSaudara[1]);
        }
      }
      cout << "Apakah terdapat ahli waris Kakek? [ya/tidak]" << endl;
      cin >> kakek;
      cout << "Apakah terdapat ahli waris Suami atau Istri? [suami/istri]"
           << endl;
      cin >> suamiIstri;
      if (suamiIstri == "suami") {
        hartaSuami = (int)(0.5 * totalHarta);
        cout << "Harta waris milik Suami = Rp" << hartaSuami << endl;
      } else {
        if (suamiIstri == "istri") {
          hartaIstri = (int)(0.25 * totalHarta);
          cout << "Harta waris milik Istri = Rp" << hartaIstri << endl;
        }
      }
      hartaSisa =
          totalHarta - (hartaSuami + hartaIstri + hartaBapak + hartaIbu +
                        hartaKakek + hartaNenek + hartaSaudaraperempuan);
      if (kakek == "ya") {
        cout << "Harta waris milik Kakek (Asabah) = Rp" << hartaSisa << endl;
      } else {
        if (jmlSaudara[0] > 0) {
          hartaSaudaralaki = (int)((double)hartaSisa / jmlSaudara[0]);
          cout << "Harta waris milik Saudara Kandung Laki-laki (Asabah, per "
                  "orang) = Rp"
               << hartaSaudaralaki << endl;
        }
      }
      cout << "Harta waris milik Saudara Kandung Perempuan (per orang) = Rp"
           << hartaSaudaraperempuan << endl;
    }
  }
  cout << "Harta waris milik Ibu = Rp" << hartaIbu << endl;
  cout << "Harta waris milik Nenek = Rp" << hartaNenek << endl;
  cout << "Apakah Anda ingin menghitung harta waris kembali? [ya/tidak]"
       << endl;
  cin >> pilihanTerakhir;
  if (pilihanTerakhir == "ya") {
    main();
  } else {
    cout << "Terima kasih sudah menggunakan program ini." << endl;
  }
}

void anakLakiYes() {
  int i, totalHarta, hartaSisa, totalKewajiban, hartaWaris, biayaPemakaman,
      bykAnak;
  int jmlAnak[2];
  string bapak, ibu, suamiIstri, pilihanTerakhir, nenek, kakek;
  int hartaSuami, hartaIstri, hartaBapak, hartaIbu, hartaKakek, hartaNenek,
      hartaAnaklaki, hartaAnakperempuan = 0;

  cout << "Masukkan jumlah anak dengan urutan anak laki-laki terlebih dahulu "
          "kemudian anak perempuan:"
       << endl;
  for (i = 0; i <= 1; i++) {
    cin >> jmlAnak[i];
  }
  cout << "Jumlah anak laki-laki dan perempuan secara berurutan adalah "
       << jmlAnak[0] << " dan " << jmlAnak[1] << endl;
  bykAnak = jmlAnak[0] + jmlAnak[1];
  cout << "Masukkan total harta yang ditinggalkan:" << endl;
  cin >> hartaWaris;
  cout << "Masukkan total biaya pemakaman:" << endl;
  cin >> biayaPemakaman;
  cout << "Masukkan total hutang yang ditinggalkan:" << endl;
  cin >> totalKewajiban;
  totalHarta = hartaWaris - (totalKewajiban + biayaPemakaman);
  cout << "Total harta yang siap diwariskan = Rp" << totalHarta << endl;
  cout << "Apakah terdapat ahli waris Bapak? [ya/tidak]" << endl;
  cin >> bapak;
  if (bapak == "ya") {
    cout << "Apakah terdapat ahli waris Ibu? [ya/tidak]" << endl;
    cin >> ibu;
    if (ibu == "ya") {
      hartaIbu = (int)((double)1 / 6 * totalHarta);
    } else {
      cout << "Apakah terdapat ahli waris Nenek? [ya/tidak]" << endl;
      cin >> nenek;
      if (nenek == "ya") {
        hartaNenek = (int)((double)1 / 6 * totalHarta);
      }
    }
    hartaBapak = (int)((double)1 / 6 * totalHarta);
  } else {
    cout << "Apakah terdapat ahli waris Ibu? [ya/tidak]" << endl;
    cin >> ibu;
    if (ibu == "ya") {
      hartaIbu = (int)((double)1 / 6 * totalHarta);
    } else {
      cout << "Apakah terdapat ahli waris Nenek? [ya/tidak]" << endl;
      cin >> nenek;
      if (nenek == "ya") {
        hartaNenek = (int)((double)1 / 6 * totalHarta);
      }
    }
    cout << "Apakah terdapat ahli waris Kakek? [ya/tidak]" << endl;
    cin >> kakek;
    if (kakek == "ya") {
      hartaKakek = (int)((double)1 / 6 * totalHarta);
    }
  }
  cout << "Apakah terdapat ahli waris Suami atau Istri? [suami/istri]" << endl;
  cin >> suamiIstri;
  if (suamiIstri == "suami") {
    hartaSuami = (int)(0.25 * totalHarta);
    cout << "Harta waris milik Suami = Rp" << hartaSuami << endl;
  } else {
    if (suamiIstri == "istri") {
      hartaIstri = (int)(0.125 * totalHarta);
      cout << "Harta waris milik Istri = Rp" << hartaIstri << endl;
    }
  }
  cout << "Harta waris milik Bapak = Rp" << hartaBapak << endl;
  cout << "Harta waris milik Ibu = Rp" << hartaIbu << endl;
  hartaSisa = totalHarta - (hartaSuami + hartaIstri + hartaBapak + hartaIbu +
                            hartaKakek + hartaNenek);
  if (jmlAnak[1] == 0) {
    hartaAnaklaki = (int)((double)hartaSisa / jmlAnak[0]);
    cout << "Harta waris milik Anak Laki-laki (Asabah, per orang) = Rp"
         << hartaAnaklaki << endl;
  } else {
    cout << "Harta waris milik Anak Laki-laki & Perempuan (Asabah) = Rp"
         << hartaSisa << endl;
    if (jmlAnak[0] == 1) {
      hartaAnaklaki = (int)((double)2 / 3 * hartaSisa / jmlAnak[0]);
    } else {
      hartaAnaklaki =
          (int)((double)(jmlAnak[0] * 2) / (jmlAnak[0] * 2 + 1) * hartaSisa);
    }
    cout << "Harta waris milik Anak Laki-laki (per orang) = Rp" << hartaAnaklaki
         << endl;
    hartaAnakperempuan =
        (int)((double)(hartaSisa - hartaAnaklaki) / jmlAnak[1]);
    cout << "Harta waris milik Anak Perempuan (per orang) = Rp"
         << hartaAnakperempuan << endl;
  }
  cout << "Apakah Anda ingin menghitung harta waris kembali? [ya/tidak]"
       << endl;
  cin >> pilihanTerakhir;
  if (pilihanTerakhir == "ya") {
    main();
  } else {
    cout << "Terima kasih sudah menggunakan program ini." << endl;
  }
}

// The following implements type conversion functions.
string toString(double value) { // int also
  stringstream temp;
  temp << value;
  return temp.str();
}

int toInt(string text) { return atoi(text.c_str()); }

double toDouble(string text) { return atof(text.c_str()); }
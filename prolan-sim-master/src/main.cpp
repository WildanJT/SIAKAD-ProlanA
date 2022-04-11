#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstdlib>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

int main(int argc, char** argv)
{
	vector<mahasiswa> recMhs;
	vector<mahasiswa>::iterator iM;
	vector<dosen> recDosen;
	vector<dosen>::iterator iD;
	vector<tendik> recTendik;
	vector<tendik>::iterator iT;

	int menu_terpilih;

	while(1) 
	{
		system("CLS");
		int jumlah_menu = 6;
		cout << "\033[1mSelamat datang di Universitas X" << endl;
		cout << "-------------------------------\n" << endl;
		cout << "Data statistik:\033[0m" << endl;
		cout << "  1. Jumlah Mahasiswa             : \033[32m" << recMhs.size() << " Mahasiswa\033[0m" << endl;
		cout << "  2. Jumlah Dosen                 : \033[32m" << recDosen.size() << " Dosen\033[0m" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : \033[32m" << recTendik.size() << " Tenaga Kependidikan\033[0m" << endl;
		cout << endl;
		cout << "\033[1mMenu:\033[0m" << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  0. \033[3mKeluar\033[0m"<<endl;
		cout << "\033[1m\n-> Menu Pilihan: ";
		cin >> menu_terpilih;
		cout << "\033[0m" << endl;
		
		for(int i=0; i<=jumlah_menu; i++)//Clearing Screen
		{
			if(menu_terpilih == i)//Only Valid Input
			{
				system("CLS");
			}
		}
		
	
		switch (menu_terpilih) 
		{	

			case 1://Menambah Data Mahasiswa
				{
					string id, nama, nrp, departemen;
					int  dd, mm, yy, tahunmasuk, semesterke, skslulus;
					cout << "\033[1mMASUKKAN DATA MAHASISWA" << endl;
					cout << "-----------------------\033[0m\n" << endl;
					cout << "Nama	: ";
					cin.ignore();
					getline(cin,nama);
					cout << "NRP	: ";
					cin >> nrp;
					cout << "\033[1m\nMasukkan Tanggal Lahir" << endl;
					cout << "----------------------\033[0m" << endl;
					cout << "Tanggal (dd)	: ";
					cin >> dd;
					cout << "Bulan (mm)	: ";
					cin >> mm;
					cout << "Tahun (yyyy)	: ";
					cin >> yy;
					cout << "\033[1m----------------------\033[0m\n" << endl;
					cout << "Departemen		: ";
					cin.ignore();
					getline(cin,departemen);
					cout << "Tahun Masuk		: ";
					cin >> tahunmasuk;
					cout << "Semester saat ini	: ";
					cin >> semesterke;
					cout << "Jumlah SKS Lulus	: ";
					cin >> skslulus;
					cout << endl;
					recMhs.push_back(mahasiswa(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus));
					if(semesterke > 1)//Mencari Nilai IP Semester
						{
							cout << "\033[1m\nMasukkan IP Semester" << endl;
							cout << "----------------------\033[0m" << endl;
							float ips;
							for(int semester = 1; semester < semesterke; semester++)
							{
								cout << "IP Semester " << semester << "	: ";
								cin >> ips;

								recMhs[recMhs.size() - 1].setIPS(semester, ips);
							}
							cout << "\033[1m----------------------\033[0m\n" << endl;
						}

				}
				break;
			
			case 2://Menambah Data Dosen
				{
					string id, nama, npp, departemen, pendidikan;
					int dd, mm, yy;
					cout << "\033[1mMASUKKAN DATA DOSEN" << endl;
					cout << "----------------------\033[0m\n" << endl;
					cout << "Nama	: ";
					cin.ignore();
					getline(cin,nama);
					cout << "NPP	: ";
					cin >> npp;
					cout << "\033[1m\nMasukkan Tanggal Lahir" << endl;
					cout << "----------------------\033[0m" << endl;
					cout << "Tanggal (dd)	: ";
					cin >> dd;
					cout << "Bulan (mm)	: ";
					cin >> mm;
					cout << "Tahun (yyyy)	: ";
					cin >> yy;
					cout << "\033[1m----------------------\033[0m\n" << endl;
					cout << "Departemen	: ";
					cin.ignore();
					getline(cin,departemen);
					cout << "Pendidikan	: ";
					getline(cin,pendidikan);
					cout << endl;
					recDosen.push_back(dosen(id, nama, dd, mm, yy, npp, departemen, pendidikan));
				}
				break;
			
			case 3://Menambah Data Tendik
				{
					string id, nama, npp, unit;
					int dd, mm, yy;
					cout << "\033[1mMASUKKAN DATA TENAGA KEPENDIDIKAN" << endl;
					cout << "------------------------------------\033[0m\n" << endl;
					cout << "Nama	: ";
					cin.ignore();
					getline(cin,nama);
					cout << "NPP	: ";
					cin >> npp;
					cout << "\033[1m\nMasukkan Tanggal Lahir" << endl;
					cout << "----------------------------\033[0m" << endl;
					cout << "Tanggal (dd): ";
					cin >> dd;
					cout << "Bulan (mm): ";
					cin >> mm;
					cout << "Tahun (yyyy): ";
					cin >> yy;
					cout << "\033[1m----------------------\033[0m\n" << endl;
					cout << "Unit	: ";
					cin.ignore();
					getline(cin,unit);
					cout << endl;
					recTendik.push_back(tendik(id, nama, dd, mm, yy, npp, unit));
				}
				break;
			
			case 4://Menampilkan Data Mahasiswa
				{
					cout << "\033[1m[DATA MAHASISWA]\033[0m" <<endl <<endl;
					if(recMhs.size() == 0)//Error Notice
					{
						cout << "\033[3;31m~Tidak Ada Data Mahasiswa~\033[0m\n" <<endl;

						cout << "\033[3m" <<endl;
						system("PAUSE");
						cout << "\033[0m";
						break;
					}
					else//Menampilkan Seluruh Data Mahasiswa
					{
						while(1)
						{
							for(unsigned i=0; i < recMhs.size(); i++)
							{
								cout << "\033[1;32m" << i + 1 << "]\033[0m";
								cout << "\033[1m -----------------------------------------------\033[0m" <<endl;
								cout << " Nama			: " << recMhs[i].getNama() <<endl;
								cout << " NRP			: " << recMhs[i].getNRP() <<endl;
								cout << " Tanggal Lahir		: " << recMhs[i].getTglLahir() <<"/"<< recMhs[i].getBulanLahir() <<"/"<<  recMhs[i].getTahunLahir() <<endl;
								cout << " Departemen		: " << recMhs[i].getDepartemen() <<endl;
								cout << " Tahun Masuk		: " << recMhs[i].getTahunMasuk() <<endl;
								cout << " Semester saat ini	: " << recMhs[i].getSemester() <<endl;
								cout << " SKS Lulus		: " << recMhs[i].getSKSLulus() <<endl;
								cout << " \033[1mData IP Semester\033[0m" <<endl;
								for(int semester = 1; semester < recMhs[i].getSemester(); semester++)
									{
										cout << "	IP Semester " << semester << "	: " << recMhs[i].getIPS(semester) <<endl;
										
									}
								float x = 0;
								float ipk = 0;
								for(int semester = 1; semester < recMhs[i].getSemester(); semester++)
									{
										x += recMhs[i].getIPS(semester);
										ipk = x/semester;
										recMhs[i].setIPK(ipk);
									}
								cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
								cout << " IP Kumulatif		: " << recMhs[i].getIPK() <<"/4.0" <<endl;
								cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
							}

							int menu;
							cout << "\033[1m\nMenu\033[0m" <<endl;
							cout << " 1. Edit Data" <<endl;
							cout << " 2. Delete Data" <<endl;
							cout << " 0. Kembali" <<endl <<endl;
							cout << "\033[1m-> Pilih Menu: ";
							cin >> menu;
							cout << "\033[0m" <<endl;
							switch (menu)
							{
								case 1://Edit Data
									{
										int pilihan, opsi;
										cout << "\033[1mPilih nomor data yang akan di edit: ";
										cin >> pilihan;
										cout <<endl;
										system("CLS");
										cout << "\033[1m[DATA YANG AKAN DI EDIT]\033[0m" <<endl <<endl;
										cout << "\033[1;32m" << pilihan << "]\033[0m";
										cout << "\033[1m -----------------------------------------------\033[0m" <<endl;
										cout << " Nama			: " << recMhs[pilihan - 1].getNama() <<endl;
										cout << " NRP			: " << recMhs[pilihan - 1].getNRP() <<endl;
										cout << " Tanggal Lahir		: " << recMhs[pilihan - 1].getTglLahir() <<"/"<< recMhs[pilihan - 1].getBulanLahir() <<"/"<<  recMhs[pilihan - 1].getTahunLahir() <<endl;
										cout << " Departemen		: " << recMhs[pilihan - 1].getDepartemen() <<endl;
										cout << " Tahun Masuk		: " << recMhs[pilihan - 1].getTahunMasuk() <<endl;
										cout << " Semester saat ini	: " << recMhs[pilihan - 1].getSemester() <<endl;
										cout << " SKS Lulus		: " << recMhs[pilihan - 1].getSKSLulus() <<endl;
										cout << " \033[1mData IP Semester\033[0m" <<endl;
										for(int semester = 1; semester < recMhs[pilihan - 1].getSemester(); semester++)
											{
												cout << "	IP Semester " << semester << "	: " << recMhs[pilihan - 1].getIPS(semester) <<endl;
												
											}
										float x = 0;
										float ipk = 0;
										for(int semester = 1; semester < recMhs[pilihan - 1].getSemester(); semester++)
											{
												x += recMhs[pilihan - 1].getIPS(semester);
												ipk = x/semester;
												recMhs[pilihan - 1].setIPK(ipk);
											}
										cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
										cout << " IP Kumulatif		: " << recMhs[pilihan - 1].getIPK() <<"/4.0" <<endl;
										cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
										cout << endl;
										cout << "Opsi Pengeditan Data\033[0m" <<endl;
										cout << " 1. Edit Nama" <<endl;
										cout << " 2. Edit NRP" <<endl;
										cout << " 3. Edit Tgl Lahir" <<endl;
										cout << " 4. Edit Departemen" <<endl;
										cout << " 5. Edit Tahun Masuk" <<endl;
										cout << " 6. Edit Semester" <<endl;
										cout << " 7. Edit SKS Lulus" <<endl;
										cout << " 8. Edit IP Semester" <<endl;
										cout << " 0. \033[3mKembali\033[0m" <<endl;
										cout << "\033[1m-> Pilih Opsi: ";
										cin >> opsi;
										cout << "\033[0m" <<endl;
										switch (opsi)
										{
											case 1://Ganti Nama
												{
													string data_baru;
													cout << "\033[1mMasukan nama baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recMhs[pilihan - 1].setNama(data_baru);

													break;
												}
											case 2://Ganti NRP
												{
													string data_baru;
													cout << "\033[1mMasukan NRP Baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recMhs[pilihan - 1].setNRP(data_baru);

													break;
												}
											case 3://Ganti Tgl Lahir
												{
													int dd, mm, yy;
													cout << "\033[1mMasukan Tgl Lahir Baru:\033[0m " <<endl;
													cout << "DD	: ";
													cin >> dd;
													cout << "MM	: ";
													cin >> mm;
													cout << "YYYY	: ";
													cin >> yy;
													recMhs[pilihan - 1].setTglLahir(dd, mm, yy);

													break;
												}
											case 4://Ganti Departemen
												{
													string data_baru;
													cout << "\033[1mMasukan Departemen Baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recMhs[pilihan - 1].setDepartemen(data_baru);

													break;
												}
											case 5://Ganti Tahun Masuk
												{
													int data_baru;
													cout << "\033[1mMasukan Tahun Masuk Baru:\033[0m ";
													cin >> data_baru;
													cout << endl;
													recMhs[pilihan - 1].setTahunMasuk(data_baru);

													break;
												}
											case 6://Ganti Semester
												{
													int data_baru;
													cout << "\033[1mMasukan Semester Baru:\033[0m ";
													cin >> data_baru;
													cout << endl;
													recMhs[pilihan - 1].setSemester(data_baru);

													break;
												}
											case 7://Ganti SKS Lulus
												{
													int data_baru;
													cout << "\033[1mMasukan SKS Lulus Baru:\033[0m ";
													cin >> data_baru;
													cout << endl;
													recMhs[pilihan - 1].setSKSLulus(data_baru);

													break;
												}
											case 8://Ganti IP Semester
												{
													int semesterke;
													semesterke = recMhs[pilihan - 1].getSemester();
													if(semesterke > 1)//Mencari Nilai IP Semester
														{
															cout << "\033[1m\nMasukkan IP Semester" << endl;
															cout << "----------------------\033[0m" << endl;
															float ips;
															for(int semester = 1; semester < semesterke; semester++)
															{
																cout << "IP Semester " << semester << "	: ";
																cin >> ips;

																recMhs[pilihan - 1].setIPS(semester, ips);
															}
															cout << "\033[1m----------------------\033[0m\n" << endl;
														}
													else
														{
															cout << "\033[3;31m~Belum Ada Semester Lulus~\033[0m\n" <<endl;

															cout << "\033[3m" <<endl;
															system("PAUSE");
															cout << "\033[0m";
															break;
														}

													break;
												}
											case 0://Keluar Edit Data
												{
													system("CLS");
													break;
												}
											default://Error Input
												{
													cout << "\033[1;31m-ERROR- \033[3;21mUnrecognisable Input!\033[0m" << endl;
													
													cout << "\033[3m" <<endl;
													system("PAUSE");
													cout << "\033[0m";
													
													system("CLS");

													break;
												}
										}
										
										system("CLS");
										break;
									}

								case 2://Hapus Data Mahasiswa
									{
										long long unsigned pilihan;
										cout << "\033[1mPilih nomor data yang akan di hapus: ";
										cin >> pilihan;
										cout << "\033[0m" <<endl;
										if(pilihan > recMhs.size())//Error Notice
										{
											cout << "\033[1;31m-ERROR- \033[3;21mUnmatch Data Input!\033[0m" << endl;
										
											cout << "\033[3m" <<endl;
											system("PAUSE");
											cout << "\033[0m";
											
											system("CLS");

											break;
										}
										iM = recMhs.begin() + pilihan - 1;
										recMhs.erase(iM);
									}


								case 0://Keluar Tampilan Data Mahasiswa
									{

										break;
									}

								default://Error Input
									{
										cout << "\033[1;31m-ERROR- \033[3;21mUnrecognisable Input!\033[0m" << endl;
										
										cout << "\033[3m" <<endl;
										system("PAUSE");
										cout << "\033[0m";
										
										system("CLS");

										break;
									}
							}

							system("CLS");
							break;

						}

						system("CLS");
						break;
					}
				}
			
			case 5://Menampilkan Data Dosen
				{
					cout << "\033[1m[DATA DOSEN]\033[0m" <<endl <<endl;
					if(recDosen.size() == 0)//Error Notice
					{
						cout << "\033[3;31m~Tidak Ada Data Dosen~\033[0m\n" <<endl;

						cout << "\033[3m" <<endl;
						system("PAUSE");
						cout << "\033[0m";
						break;
					}
					else//Menampilkan Seluruh Data Dosen
					{
						while(1)
						{
							for(unsigned i=0; i < recDosen.size(); i++)
							{
								cout << "\033[1;32m" << i + 1 << "]\033[0m";
								cout << "\033[1m -----------------------------------------------\033[0m" <<endl;
								cout << " Nama			: " << recDosen[i].getNama() <<endl;
								cout << " NPP			: " << recDosen[i].getNPP() <<endl;
								cout << " Tanggal Lahir		: " << recDosen[i].getTglLahir() <<"/"<< recDosen[i].getBulanLahir() <<"/"<<  recDosen[i].getTahunLahir() <<endl;
								cout << " Departemen		: " << recDosen[i].getDepartemen() <<endl;
								cout << " Pendidikan		: " << recDosen[i].getPendidikan() <<endl;
								cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
							}

							int menu;
							cout << "\033[1m\nMenu\033[0m" <<endl;
							cout << " 1. Edit Data" <<endl;
							cout << " 2. Delete Data" <<endl;
							cout << " 0. Kembali" <<endl <<endl;
							cout << "\033[1m-> Pilih Menu: ";
							cin >> menu;
							cout << "\033[0m" <<endl;
							switch (menu)
							{
								case 1://Edit Data
									{
										int pilihan, opsi;
										cout << "\033[1mPilih nomor data yang akan di edit: ";
										cin >> pilihan;
										system("CLS");
										cout << "\033[1m[DATA YANG AKAN DI EDIT]\033[0m" <<endl <<endl;
										cout << "\033[1;32m" << pilihan << "]\033[0m";
										cout << "\033[1m -----------------------------------------------\033[0m" <<endl;
										cout << " Nama			: " << recDosen[pilihan - 1].getNama() <<endl;
										cout << " NPP			: " << recDosen[pilihan - 1].getNPP() <<endl;
										cout << " Tanggal Lahir		: " << recDosen[pilihan - 1].getTglLahir() <<"/"<< recDosen[pilihan - 1].getBulanLahir() <<"/"<<  recDosen[pilihan - 1].getTahunLahir() <<endl;
										cout << " Departemen		: " << recDosen[pilihan - 1].getDepartemen() <<endl;
										cout << " Pendidikan		: " << recDosen[pilihan - 1].getPendidikan() <<endl;
										cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
										cout << endl;
										cout << "Opsi Pengeditan Data\033[0m" <<endl;
										cout << " 1. Edit Nama" <<endl;
										cout << " 2. Edit NPP" <<endl;
										cout << " 3. Edit Tgl Lahir" <<endl;
										cout << " 4. Edit Departemen" <<endl;
										cout << " 5. Edit Pendidikan" <<endl;
										cout << " 0. \033[3mKembali\033[0m" <<endl;
										cout << "\033[1m-> Pilih Opsi: ";
										cin >> opsi;
										cout << "\033[0m" <<endl;
										switch (opsi)
										{
											case 1://Ganti Nama
												{
													string data_baru;
													cout << "\033[1mMasukan nama baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recDosen[pilihan - 1].setNama(data_baru);

													break;
												}
											case 2://Ganti NPP
												{
													string data_baru;
													cout << "\033[1mMasukan NPP Baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recDosen[pilihan - 1].setNPP(data_baru);

													break;
												}
											case 3://Ganti Tgl Lahir
												{
													int dd, mm, yy;
													cout << "\033[1mMasukan Tgl Lahir Baru:\033[0m " <<endl;
													cout << "DD	: ";
													cin >> dd;
													cout << "MM	: ";
													cin >> mm;
													cout << "YYYY	: ";
													cin >> yy;
													recDosen[pilihan - 1].setTglLahir(dd, mm, yy);

													break;
												}
											case 4://Ganti Departemen
												{
													string data_baru;
													cout << "\033[1mMasukan Departemen Baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recDosen[pilihan - 1].setDepartemen(data_baru);

													break;
												}
											case 5://Ganti Pendidikan
												{
													string data_baru;
													cout << "\033[1mMasukan Pendidikan Baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recDosen[pilihan - 1].setPendidikan(data_baru);

													break;
												}
											case 0://Keluar Edit Data
												{
													system("CLS");
													break;
												}
											default://Error Input
												{
													cout << "\033[1;31m-ERROR- \033[3;21mUnrecognisable Input!\033[0m" << endl;
													
													cout << "\033[3m" <<endl;
													system("PAUSE");
													cout << "\033[0m";
													
													system("CLS");

													break;
												}
										}
										
										system("CLS");
										break;
									}

								case 2://Hapus Data Dosen
									{
										long long unsigned pilihan;
										cout << "\033[1mPilih nomor data yang akan di hapus: ";
										cin >> pilihan;
										cout << "\033[0m" <<endl;
										if(pilihan > recDosen.size())
										{
											cout << "\033[1;31m-ERROR- \033[3;21mUnmatch Data Input!\033[0m" << endl;
										
											cout << "\033[3m" <<endl;
											system("PAUSE");
											cout << "\033[0m";
											
											system("CLS");

											break;
										}
										iD = recDosen.begin() + pilihan - 1;
										recDosen.erase(iD);
									}


								case 0://Keluar Tampilan Data Dosen
									{

										break;
									}

								default://Error Input
									{
										cout << "\033[1;31m-ERROR- \033[3;21mUnrecognisable Input!\033[0m" << endl;
										
										cout << "\033[3m" <<endl;
										system("PAUSE");
										cout << "\033[0m";
										
										system("CLS");

										break;
									}
							}

							system("CLS");
							break;
						}

						system("CLS");
						break;
					}
				}
			
			case 6://Menampilkan Data Tendik
				{
					cout << "\033[1m[DATA TENAGA KEPENDIDIKAN]\033[0m" <<endl <<endl;
					if(recTendik.size() == 0)//Error Notice
					{
						cout << "\033[3;31m~Tidak Ada Data Tenaga Kependidikan~\033[0m\n" <<endl;

						cout << "\033[3m" <<endl;
						system("PAUSE");
						cout << "\033[0m";
						break;
					}
					else//Menampilkan Seluruh Data Tendik
					{
						while(1)
						{
							for(unsigned i=0; i < recTendik.size(); i++)
							{
								cout << "\033[1;32m" << i + 1 << "]\033[0m";
								cout << "\033[1m -----------------------------------------------\033[0m" <<endl;
								cout << " Nama		: " << recTendik[i].getNama() <<endl;
								cout << " NPP		: " << recTendik[i].getNPP() <<endl;
								cout << " Tanggal Lahir	: " << recTendik[i].getTglLahir() <<"/"<< recTendik[i].getBulanLahir() <<"/"<<  recTendik[i].getTahunLahir() <<endl;
								cout << " Unit		: " << recTendik[i].getUnit() <<endl;
								cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
							}

							int menu;
							cout << "\033[1m\nMenu\033[0m" <<endl;
							cout << " 1. Edit Data" <<endl;
							cout << " 2. Delete Data" <<endl;
							cout << " 0. Kembali" <<endl <<endl;
							cout << "\033[1m-> Pilih Menu: ";
							cin >> menu;
							cout << "\033[0m" <<endl;
							switch (menu)//Edit Data
							{
								case 1://Edit Data Tendik
									{
										int pilihan, opsi;
										cout << "\033[1mPilih nomor data yang akan di edit: ";
										cin >> pilihan;
										system("CLS");
										cout << "\033[1m[DATA YANG AKAN DI EDIT]\033[0m" <<endl <<endl;
										cout << "\033[1;32m" << pilihan << "]\033[0m";
										cout << "\033[1m -----------------------------------------------\033[0m" <<endl;
										cout << " Nama		: " << recTendik[pilihan - 1].getNama() <<endl;
										cout << " NPP		: " << recTendik[pilihan - 1].getNPP() <<endl;
										cout << " Tanggal Lahir	: " << recTendik[pilihan - 1].getTglLahir() <<"/"<< recTendik[pilihan - 1].getBulanLahir() <<"/"<<  recTendik[pilihan - 1].getTahunLahir() <<endl;
										cout << " Unit		: " << recTendik[pilihan - 1].getUnit() <<endl;
										cout << "\033[1m--------------------------------------------------\033[0m" <<endl;
										cout << endl;
										cout << "Opsi Pengeditan Data\033[0m" <<endl;
										cout << " 1. Edit Nama" <<endl;
										cout << " 2. Edit NPP" <<endl;
										cout << " 3. Edit Tgl Lahir" <<endl;
										cout << " 4. Edit Unit" <<endl;
										cout << " 0. \033[3mKembali\033[0m" <<endl;
										cout << "\033[1m-> Pilih Opsi: ";
										cin >> opsi;
										cout << "\033[0m" <<endl;
										switch (opsi)
										{
											case 1://Ganti Nama
												{
													string data_baru;
													cout << "\033[1mMasukan nama baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recTendik[pilihan - 1].setNama(data_baru);

													break;
												}
											case 2://Ganti NPP
												{
													string data_baru;
													cout << "\033[1mMasukan NPP Baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recTendik[pilihan - 1].setNPP(data_baru);

													break;
												}
											case 3://Ganti Tgl Lahir
												{
													int dd, mm, yy;
													cout << "\033[1mMasukan Tgl Lahir Baru:\033[0m " <<endl;
													cout << "DD	: ";
													cin >> dd;
													cout << "MM	: ";
													cin >> mm;
													cout << "YYYY	: ";
													cin >> yy;
													recTendik[pilihan - 1].setTglLahir(dd, mm, yy);

													break;
												}
											case 4://Ganti Unit
												{
													string data_baru;
													cout << "\033[1mMasukan Unit Baru:\033[0m ";
													cin.ignore();
													getline(cin,data_baru);
													cout << endl;
													recTendik[pilihan - 1].setUnit(data_baru);

													break;
												}
											case 0://Keluar Edit Data
												{
													system("CLS");
													break;
												}
											default://Error Input
												{
													cout << "\033[1;31m-ERROR- \033[3;21mUnrecognisable Input!\033[0m" << endl;
													
													cout << "\033[3m" <<endl;
													system("PAUSE");
													cout << "\033[0m";
													
													system("CLS");

													break;
												}
										}
										
										system("CLS");
										break;
									}

								case 2://Hapus Data Tendik
									{
										long long unsigned pilihan;
										cout << "\033[1mPilih nomor data yang akan di hapus: ";
										cin >> pilihan;
										cout << "\033[0m" <<endl;
										if(pilihan > recTendik.size())
										{
											cout << "\033[1;31m-ERROR- \033[3;21mUnmatch Data Input!\033[0m" << endl;
										
											cout << "\033[3m" <<endl;
											system("PAUSE");
											cout << "\033[0m";
											
											system("CLS");

											break;
										}
										iT = recTendik.begin() + pilihan - 1;
										recTendik.erase(iT);
									}

								case 0://Keluar Tampilan Data Tendik
									{

										break;
									}

								default://Error Input
									{
										cout << "\033[1;31m-ERROR- \033[3;21mUnrecognisable Input!\033[0m" << endl;
										
										cout << "\033[3m" <<endl;
										system("PAUSE");
										cout << "\033[0m";
										
										system("CLS");

										break;
									}
							}

							system("CLS");
							break;
						}

						system("CLS");
						break;
					}
				}
			
			case 0://Keluar System
				{
					system("CLS");
					return 0;	
				}
			
			default://Error Notice
				{
					cout << "\033[1;31m-ERROR- \033[3;21mUnrecognisable Input!\033[0m" << endl;
					
					cout << "\033[3m" <<endl;
					system("PAUSE");
					cout << "\033[0m";
					
					system("CLS");

					break;
				}
		}
	}
}
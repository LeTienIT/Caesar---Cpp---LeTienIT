#include <iostream>
#include "data.h"
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

bool check_ChuoiDL(string chuoiDL)
{
	doDai = chuoiDL.length();
	if(doDai >= ARRAY_SIZE)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool check_Khoa(string khoaS)
{
	stringstream ss(khoaS);
    ss >> khoa;
    if (ss.fail() || !ss.eof()) {
        return false;
    }
    if(abs(khoa) > 97)
    {
    	cout<<"Vi khoa co tri tuyet doi > 97. Vi vay se duoc thay the bang: "<<(khoa%97)<<'\n';
	}
	return true;
}
bool xu_ly_du_lieu(string chuoiDL,int key)
{
	for(int i = 0 ; i < doDai ; i++)
	{
		bool check = false;
		char c = chuoiDL[i];
			
		for(int j = 0 ; j < 97; j++)
		{
			if(bangASCII[j] == c)
			{
				if(key == 1)
				{
					banRo[i] = j;
				}
				else
				{
					banMa[i] = j;
				}
				check = true;
				break;
			}
		}
		if(check == false)
		{
			cout<<"LOI!Khong the xu ly ky tu: "<<c<<"\n";
			return false;
		}
	}
	return true;
}
bool thuat_toan_caesar(int key)
{
	try
	{
		for(int i=0; i<doDai; i++)
		{
			if(key == 1)
			{
				int tmp = banRo[i] + khoa;
				while(tmp<0)
				{
					tmp+=97;
				}
				banMa[i] = tmp%97;				
			}
			else
			{
				int tmp = (banMa[i] - khoa);
                while (tmp < 0)
                {
                    tmp += 97;
                }
                banRo[i] = (tmp % 97);
			}
		}	
		return true;	
	}
	catch(exception& e)
	{
		return false;
	}
}
string hien_thi_dau_ra(int key)
{
	string chuoiDauRa = "";
	try
	{
		for(int i=0;i<doDai;i++)
		{
			char c;
			if(key == 1)
			{
				c = bangASCII[banMa[i]];
			}
			else
			{
				c = bangASCII[banRo[i]];
			}
			chuoiDauRa+=c;
		}
		return chuoiDauRa;		
	}catch(exception& e)
	{
		return "Loi khong the xu ly du lieu";
	}
}
int main() 
{
	bool menu = true;
	string chuoiDL; string khoaS;
	while(menu)
	{
		cout<<'\n';
		cout<<"\n=====================CAESAR=====================\n";
		int chon;bool check = false;
		do
		{
			cout<<"1. Ma Hoa\n";
			cout<<"2. Giai Ma\n";
			cout<<"Lua chon khac de thoat\n";
			
			string luaChon;
			cout<<"Nhap lua chon: ";
			getline(cin,luaChon);
			
			stringstream ss(luaChon);
		    ss >> chon;
		    if (ss.fail() || !ss.eof()) {
		    	cout<<"Lua chon khong phai la so\n";
		    	cout<<"\n========================================================================================\n";
	        	check = true;
			}
			else
			{
				check = false;
			}
		}while(check);
		
		switch(chon)
		{
			case 1:
				{
					cout<<"Nhap chuoi du lieu: ";
					getline(cin,chuoiDL);
					cout<<"Nhap khoa: ";
					getline(cin,khoaS);
					if(check_ChuoiDL(chuoiDL))
					{
						if(check_Khoa(khoaS))
						{
							if(xu_ly_du_lieu(chuoiDL,1))
							{
								if(thuat_toan_caesar(1))
								{
									cout<<"Du Lieu Ma Hoa: "<<hien_thi_dau_ra(1);
								}
								else
								{
									cout<<"Ma hoa khong thanh cong, LOI\n";
								}
							}
							else
							{
								cout<<"Khoi tao du lieu that bai, khong the ma hoa\n";
							}
						}
						else
						{
							cout<<"Khoa du lieu khong hop le\n";			
						}
					}
					else
					{
						cout<<"So ky tu qua lon khong the ma hoa\n";
					}
					cout<<"\n========================================================================================\n";
				};break;
			case 2:
				{
					cout<<"Nhap chuoi du lieu: ";
					getline(cin,chuoiDL);
					cout<<"Nhap khoa: ";
					getline(cin,khoaS);
					if(check_ChuoiDL(chuoiDL))
					{
						if(check_Khoa(khoaS))
						{
							if(xu_ly_du_lieu(chuoiDL,2))
							{
								if(thuat_toan_caesar(2))
								{
									cout<<"Du Lieu Giai Ma: "<<hien_thi_dau_ra(2);
								}
								else
								{
									cout<<"Giai Ma khong thanh cong, LOI\n";
								}
							}
							else
							{
								cout<<"Khoi tao du lieu that bai, khong the ma hoa\n";
							}
						}
						else
						{
							cout<<"Khoa du lieu khong hop le\n";			
						}
					}
					else
					{
						cout<<"So ky tu qua lon khong the giai ma\n";
					}
					cout<<"\n========================================================================================\n";
				};break;
			default: 
			{
				menu = false;	
			};break;
		}
	}
	
	
//	cout<<check_ChuoiDL(chuoiDL)<<'\n';
//	cout<<check_Khoa(khoaS)<<'\n';
//	cout<<"KHOA: "<<khoa<<'\n';
//	cout<<xu_ly_du_lieu(chuoiDL)<<'\n';
	return 0;
}

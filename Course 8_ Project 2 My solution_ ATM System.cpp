#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const string ClientsFileName = "Client.txt";

enum enMainMenuOptions {
	QuickWithdraw = 1, NormalWithdraw = 2, Deposit = 3,
	CheckBalance = 4, Logout = 5
};
enum enQuickWithdrawOptions {
	Choice1 = 20, Choice2 = 50, Choice3 = 100, Choice4 = 200,
	Choice5 = 400, Choice6 = 600, Choice7 = 800, Choice8 = 1000
};
struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string AccountName = "";
	string Phone = "";
	double AccountBalance = 0;

};

void Login();
void ShowAtmMenuScreen();

sClient CurrentClient;

vector<string> SplitString(string s1, string delimi)
{
	short pos = 0;
	string sWord;
	vector<string> vWords;
	while ((pos = s1.find(delimi)) != std::string::npos)
	{
		sWord = s1.substr(0, pos);
		if (sWord != "")
		{
			vWords.push_back(sWord);
		}
		s1.erase(0, pos + delimi.length());
	}
	if (s1 != "")
	{
		vWords.push_back(s1);
	}
	return vWords;
}
sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.AccountName = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;


}
vector<sClient> LoadDataFromFile(string FileName)
{
	vector<sClient> vClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Record;

		while (getline(MyFile, Line))
		{
			Record = ConvertLineToRecord(Line);

			vClient.push_back(Record);
		}
		MyFile.close();
	}
	return vClient;
}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.AccountName + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;

}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{

		for (sClient& C : vClients)
		{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;

		}

		MyFile.close();

	}

	return vClients;

}


bool FindClientByAccountNumberAndPincode(string AccountNumber, string Pincode, sClient& CurrentClient)
{
	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);

	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == Pincode)
		{
			CurrentClient = C;
			return true;
		}
	}
	return false;
}
bool LoadClientInfo(string AccountNumber, string Pincode)
{
	if (FindClientByAccountNumberAndPincode(AccountNumber, Pincode, CurrentClient))
		return true;
	else
		return false;
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menu....\n";
	system("pause>0");

	ShowAtmMenuScreen();
}
short ReadQuickWithdrawOptions()
{
	short Option = 0;
	cout << "Chose what to do from [1] to [9] ? ";
	cin >> Option;

	return Option;
}
void ChangeClientBalance(sClient Client)
{
	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);

	for (sClient& C : vClients)
	{
		if (C.AccountNumber == Client.AccountNumber && C.PinCode == Client.PinCode)
		{
			C = Client;	
			break;

		}
	}

	SaveCleintsDataToFile(ClientsFileName, vClients);
	cout << "\nDone successfully. New balance is: " << Client.AccountBalance;
}
bool VerifyTransactionApproval()
{
	char Answer = 'y';
	cout << "\nAre you sure you want perform this transaction? y/n? ";
	cin >> Answer;

	return tolower(Answer) == 'y';
}
void PerformQuickWithdrawOption(short Option)
{

	switch (Option)
	{
	case 1:
	{   
		 
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice1)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice1;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 2:
	{
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice2)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice2;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 3:
	{
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice3)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice3;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 4:
	{
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice4)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice4;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 5:
	{
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice5)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice5;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 6:
	{
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice6)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice6;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 7:
	{
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice7)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice7;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 8:
	{
		if (CurrentClient.AccountBalance >= enQuickWithdrawOptions::Choice8)
		{
			if (VerifyTransactionApproval())
			{
				CurrentClient.AccountBalance -= enQuickWithdrawOptions::Choice8;
				ChangeClientBalance(CurrentClient);
			}
		}
		else
		{
			cout << "\nThe amount exceeds your balance, make another choice.";
		}
		break;
	}
	case 9:
	{
		ShowAtmMenuScreen();
	}
	}
}

void ShowCheckBalanceScreen()
{
	cout << "===================================\n";
	cout << "\t Check Balance Screen\n";
	cout << "===================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << endl;
}
void ShowQuickWithdrawScreen()
{
	cout << "===================================\n";
	cout << "\tQuick Withdraw Screen\n";
	cout << "===================================\n";

	cout << "\t[1] 20 \t\t[2] 50\n";
	cout << "\t[3] 100\t\t[4] 200\n";
	cout << "\t[5] 400\t\t[6] 600\n";
	cout << "\t[7] 800\t\t[8] 1000\n";
	cout << "\t[9] Exit\n";					
	cout << "===================================\n";
	cout << "Your Balance is: " << CurrentClient.AccountBalance << endl;
	PerformQuickWithdrawOption(ReadQuickWithdrawOptions());
}
void ShowNormalWithdrawScreen() 
{
	cout << "===================================\n";
	cout << "\tNormal Withdraw Screen\n";
	cout << "===================================\n";

	int Amount = 0;
	do{
		cout << "\nEnter an amount multiple of 5's ? ";
		cin >> Amount;
	 } while (Amount % 5 != 0);

	if (Amount <= CurrentClient.AccountBalance)
	{
		if (VerifyTransactionApproval())
		{
			CurrentClient.AccountBalance -= Amount;
			ChangeClientBalance(CurrentClient);
		}
	}
	else
	{
		cout << "\nThe amount exceeds your balance, make another choice.";   
	}

}
void ShowDepositScreen()
{
	cout << "===================================\n";
	cout << "\tDeposit Screen\n";
	cout << "===================================\n";
		
	int AmountToDeposit = 0;
	do
	{
		cout << "Enter a positive Deposit amount ";
		cin >> AmountToDeposit;
	} while (AmountToDeposit <= 0);
	
	if (VerifyTransactionApproval())
	{
		CurrentClient.AccountBalance += AmountToDeposit;
		ChangeClientBalance(CurrentClient);
	}

}

short ReadAtmMenuOption()
{
	short option = 0;
	cout << "Chose what do you want to do? [1 to 5]? ";
	cin >> option;

	return option;
}
void PerformAtmMenuOption(enMainMenuOptions Option)
{
	switch (Option)
	{
	case enMainMenuOptions::QuickWithdraw:
	{
		system("cls");
		ShowQuickWithdrawScreen();
		GoBackToMainMenu();
	}
	case enMainMenuOptions::NormalWithdraw:
	{
		system("cls");
		ShowNormalWithdrawScreen();
		GoBackToMainMenu();
	}
	case enMainMenuOptions::Deposit:
	{
		system("cls");
		ShowDepositScreen();
		GoBackToMainMenu();
	}
	case enMainMenuOptions::CheckBalance:
	{
		system("cls");
		ShowCheckBalanceScreen();
		GoBackToMainMenu();
		break;
	}
	case enMainMenuOptions::Logout:
	{
		Login();
		break;
	}
	}
}

void ShowAtmMenuScreen()
{
	system("cls");
	cout << "===================================\n";
	cout << "\tATM Main Menu Screen\n";
	cout << "===================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "===================================\n";

	PerformAtmMenuOption((enMainMenuOptions)ReadAtmMenuOption());
}
void Login()
{
	bool LoginFailed = false;
	string AccountNumber, Pincode;

	do
	{
		system("cls");
		cout << "\n------------------------------\n";
		cout << "\tLogin Screen\n";
		cout << "------------------------------\n";

		if (LoginFailed)
		{
			cout << "Invalid Account Number/Pincode!\n";
		}

		cout << "Enter Account Number? ";
		getline(cin >> ws, AccountNumber);
		cout << "Enter Pincode? ";
		getline(cin >> ws, Pincode);

		LoginFailed = !LoadClientInfo(AccountNumber, Pincode);

	} while (LoginFailed);

	ShowAtmMenuScreen();
}

int main()
{
	Login(); 

	system("pause>0");
	return 0;
}

//Second repeat 


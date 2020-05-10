#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Patient{
	int age;
	char firstName[30];
	char lastName[30];
	//Symptoms
	int isDiabetic;
	int isHypertension;
	int isAsthama;
	int isSmoker;
	//isMale 0=Male	1=Female 2=Others (lol)
	int isMale;
	//Travel 0= noTravel	1= 7days	2= 14days	3=1Month
	int travelForeign;
	int travelDomestic;
	//0= Rural	1= Urban
	int isUrban;
	//Infection type  0=Mild 1=Moderate 2=Severe
	int infectionType;
	//0=dead 1=active 2=cured
	int caseType;
	//0=green 1=orange 2=red
	int zone;
public:
	Patient()
	{

	}
	void writeToFile(fstream& f)
	{
		//0-notravel 1-last7days 2-last14days 3-last month
		//1-mild 2-moderate 3-severe
		//0-female 1-male
		//All symptoms 0-no 1-yes
		//case condition 0-dead 1-active 2-cured
		//zones 0-red 1-orange 2-green
		//DO error Handling if possible!
		cout<<"AGE : ";
		cin>>age;
		cout<<"Name (Name Space LastName): ";
		cin>>firstName>>lastName;
		cout<<"isDiabetic : ";
		cin>>isDiabetic;
		cout<<"isHypertension ";
		cin>>isHypertension;	
		cout<<"Smoker\? (1-yes,0-no): ";
		cin>>isSmoker;
		cout<<"Gender\? (1-male,0-female): ";
		cin>>isMale;
		cout<<"Travelled Domestic? (0-notravel 1-last7days 2-last14days 3-last month): ";
		cin>>travelDomestic;
		cout<<"Travelled Foreign? (0-notravel 1-last7days 2-last14days 3-last month)";
		cin>>travelForeign;		
		cout<<"Urban(1) / Rural(0)? : ";
		cin>>isUrban;
		cout<<"Nature of infection? (1-Mild 2-Moderate 3-Severe)";
		cin>>infectionType;
		cout<<"Case Type (0-dead 1-active 2-cured)? : ";
		cin>>caseType; 
		cout<<"Zone where case was diagnosed?(0-red 1-orange 2-green) : ";
		cin>>zone;
		f.write((char*)&(*this), sizeof(*this));

	}
	void readFromFile(fstream& f)
	{
		//fstream f;
		//f.open("player.txt",ios::in);
		cout<<"The players are :\n"<<endl;
		f.seekg(ios::beg);
		do
		{
			f.read((char*)&(*this), sizeof(*this));
			//f.seekg(i*sizeof(*this), ios::beg);
			if(f.eof())
				break;
			displayObj();
		}while(!f.eof());		
		//f.close();
		
	}
	void readNext(fstream& f)
	{
		f.read((char*)&(*this), sizeof(*this));
		if(f.eof())
		{
			cout<<"End of file!(Error going to next patient after Last one!"<<endl;
			return;
		}
		displayObj();
	}

	void readPrevious(fstream& f)
	{
		f.seekg(-2*sizeof(*this), ios::cur);
		if(f.tellg()<0)
		{
			cout<<"Starting of file!(Error going to Previous patient before 1st Patient!"<<endl;
			f.seekg(0,ios::beg);
			return;
		}
		f.read((char*)&(*this), sizeof(*this));
		displayObj();
	}

	int search(fstream& f, const char* n)
	{
		f.seekg(ios::beg);
		do
		{
			f.read((char*)&(*this), sizeof(*this));
			//f.seekg(i*sizeof(*this), ios::beg);
			//String is case senstive!! what to do?
			if(!strcmp(n,name))
				return 1;
		}while(!f.eof());
		return 0;
	}

	int search(fstream& f, int a)
	{
		f.seekg(ios::beg);
		do
		{
			f.read((char*)&(*this), sizeof(*this));
			//f.seekg(i*sizeof(*this), ios::beg);
			if(age==a)
				return 1;
		}while(!f.eof());
		return 0;		
	}
	
	void displayObj()
	{
		//below coutS jst to check whether it's working or not
		cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
		cout<<"Symptoms:\n";

		cout<<"Diabetic:";
		if(isDiabetic)
			cout<<"Yes.";
		else
			cout<<"No.";
		
		cout<<"\tHypertension: ";
		if(isHypertension)
			cout<<"Yes."<<endl;
		else
			cout<<"No.";

		cout"\nAsthama: ";
		if(isAsthama)
			cout<<"Yes.";
		else
			cout<<"No.";

		cout<<"\tSmoker: ";
		if(isSmoker)
			cout<<"Yes.";
		else
			cout<<"No.";

		cout<<"\nLocality: ";
		if(isUrban)
			cout<<"Urban. ";
		else
			cout<<"Rural. ";

		cout<<"Gender: ";
		if(isMale)
			cout<<"M.";
		else
			cout<<"F.";

		cout<<"\nRecent Travel History:\n";
		cout<<"Domestic: ";
		switch(travelDomestic)
		{
			case 0:
				cout<<"No Recent Travel.";
				break;
			case 1:
				cout<<"Travelled within previous 7 days.";
				break;
			case 2:
				cout<<"Travelled within previous 14 days.";
				break;
			case 3:
				cout<<"Travelled within last month.";
				break;
		}
		cout<<"\nForeign: ";
		switch(travelForeign)
		{
			case 0:
				cout<<"No Recent Travel.";
				break;
			case 1:
				cout<<"Travelled within previous 7 days.";
				break;
			case 2:
				cout<<"Travelled within previous 14 days.";
				break;
			case 3:
				cout<<"Travelled within last month.";
		}
		cout<<"\nNature of Infection: ";
		switch(infectionType)
		{	
			case 1:
				cout<<"Mild.";
				break;
			case 2:
				cout<<"Moderate.";
				break;
			case 3:
				cout<<"Severe.";
		}
		cout<<"\nCase Condition: ";
		switch(caseType)
		{	
			case 0:
				cout<<"Deceased."
				break;
			case 1:
				cout<<"Active.";
				break;
			case 2:
				cout<<"Cured.";
		}
		cout<<"\nZone(where detected): ";
		switch(zone)
		{
			case 0:
				cout<<"Red."
				break;
			case 1:
				cout<<"Orange.";
				break;
			case 2:
				cout<<"Green.";
		}
		cout<<endl<<endl<<endl<<endl;
	}
	/*Had written this Function for average in Cricket
	int search(fstream& f, float a)
	{
		f.seekg(ios::beg);
		do
		{
			f.read((char*)&(*this), sizeof(*this));
			//f.seekg(i*sizeof(*this), ios::beg);
			if(avg==a)
				return 1;
		}while(!f.eof());
		return 0;		
	}*/
};
int main()
{
	fstream f;
	f.open("patient.txt",ios::in |ios::out);
	Patient p1;
	f.seekg(ios::beg);
	/*cout<<"Previous :\n";
	p1.readNext(f);
	p1.readNext(f);
	p1.readNext(f);
	p1.readNext(f);
	p1.readPrevious(f);
	p1.readPrevious(f);	
	p1.readPrevious(f);	
	/*
	//test case to evaluate the end conditions of the file
	cout<<"Previous :\n";
	p1.readNext(f);
	p1.readNext(f);
	p1.readNext(f);
	p1.readPrevious(f);
	p1.readPrevious(f);	
	p1.readPrevious(f);	
	//write to file
	int cont;
	do{
		p1.writeToFile(f);
		cout<<"Continue : ";
		cin>>cont;
	}while(cont==1);

	//check on readNext
	cout<<"First 2: \n";
	p1.readNext(f);
	p1.readNext(f);
	//check on readPrevious
	cout<<"Previous :\n";
	p1.readPrevious(f);
	cout<<endl<<endl;
	//check on all file at once
	p1.readFromFile(f);
	cout<<endl<<endl;
	//search func
	if(p1.search(f,"rutik"))
		cout<<"rutik found";
	else
		cout<<"rutik not found";
	cout<<endl;
	if(p1.search(f,18))
		cout<<"a patient of age 18 found";
	else
		cout<<"a patient of age 18 not found";
	cout<<endl;
	*/
	f.close();
	return 0;
}
/*
when i used readFromFile i.e all objects
ubuntu@DESKTOP-4FQXGZ1:~$ cd //mnt/z/covid
ubuntu@DESKTOP-4FQXGZ1://mnt/z/covid$ g++ corona.cpp
ubuntu@DESKTOP-4FQXGZ1://mnt/z/covid$ ./a.out
The players are :

Age: 20Name: sohil
Diabetic:0
Hypertension: 1
Asthama: 0
Smoker: 1
isMale: 0
travelForeign: 0
travelDomestic: 1
isUrban: 1
Nature of Infection: 2
Case Condition: 3
Zone: 2



Age: 19Name: aditya
Diabetic:1
Hypertension: 0
Asthama: 0
Smoker: 0
isMale: 0
travelForeign: 1
travelDomestic: 0
isUrban: 1
Nature of Infection: 2
Case Condition: 1
Zone: 1



Age: 69Name: rutik
Diabetic:0
Hypertension: 1
Asthama: 0
Smoker: 0
isMale: 1
travelForeign: 3
travelDomestic: 1
isUrban: 1
Nature of Infection: 1
Case Condition: 0
Zone: 2





ubuntu@DESKTOP-4FQXGZ1://mnt/z/covid$  
*/
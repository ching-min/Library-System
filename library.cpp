#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
class student{
	private:
		string id;
		string name;
		string depart;
		string email;
		string borrow[10];
	public:
		student(){
			
		}
		/*bool check(string id);//check repeated id*/
		void add();
		void add(string,string,string,string,string[]);
		string getid(){
			return id;
		}
		string getmail(){
			return email;
		}
		void print(){
			cout<<id<<endl<<name<<endl<<depart<<endl<<email<<endl;
			/*int i=0;
			while(borrow[i].length()!=0){
				cout<<borrow[i]<<endl;
				i++;
			}*/
		}
};
class book{
	private:
		string isbn;
		string title;
		string author[10];//at most 10 authors
		string publisher;
		int year;
		int quantity;
	public:
		void add();
};

void readfile(string (&st)[10]){
	fstream file;
	file.open("student.txt",fstream::in | fstream::out | fstream::app);
	int i=0;
	int j=0;
	if(file.is_open()){
		for(string line; getline( file, line ); ){
			st[i]+=line;
			st[i]+='\n';
			j++;
			if(j==5){
				i++;
			}
		}
	} 
	file.close();
}
void split_data_s(string st[10],string &id,string &name,string &depart,string &email,string (&borrow)[10],int &c){//classify each student's data
	int i=0;
	string data[5];
	int j=0;
	while(st[c][i]!=NULL){
		if(st[c][i]!='\n'){
			data[j]+=st[c][i];
		}else{
			j++;
		}
		i++;
	}
	id.clear();
	id+=data[0];
	name.clear();
	name+=data[1];
	depart.clear();
	depart+=data[2];
	email.clear();
	email+=data[3];
	int k=0;
	for(int q=0;q<1;q++){
		borrow[q].clear();
	} 
	i=0;
	while(data[4][i]!=NULL){
		if(st[4][i]!='\n'){
			borrow[k]+=data[4][i];
		}else{
			k++;
		}
		i++;
	}
	c++;
}

bool query(string k,char op){
	if(op==s){
		
	} 
}
void admin(student (&s)[10],book (&b)[10]){
	int ac;
			bool stop=false;
			cout<<"enter the action: "<<endl
				<<"0:add a new student"<<endl
				<<"1:delete a student"<<endl
				<<"2:modify student's data"<<endl
				<<"3:query student's data"<<endl
				<<"4:print out students' data in a txt file"<<endl
				<<"5:add a new book"<<endl
				<<"6:delete a book"<<endl
				<<"7:modify book's data"<<endl
				<<"8:query book's data"<<endl
				<<"9:print out books' data in a txt file"<<endl
				<<"10:logout"<<endl;
			cin>>ac;
			while(!stop){
				switch(ac){
					case 0:
						int i;
						for(i=0;i<10;i++){
							if(s[i].getid().length()==0){
								break;
							}
						}
						if(i==10){
							cout<<"the number of student have reached the limit, you can't add a new student!"<<endl;
						}else{
							s[i].add();
						}
						break;
					case 1:
						cout<<"please enter the id of student who you want to delete: ";
						string k;
						getline(cin,k);
						query(k,"s");
						break;
				}
			}
}
int main(){
	student s[10];
	book b[10];
/*	//read file
	string st[10];
	string id;
	string name;
	string depart;
	string email;
	string borrow[10];
	readfile(st);
	int c=0;//the num of student
	while(st[c][0]!=NULL){
		split_data_s(st,id,name,depart,email,borrow,c);
		s[c].add(id,name,depart,email,borrow);
		c++;
	}*/
	
	//login
	string idf;
	cout<<"-- login --"<<endl<<"administer: admin"<<endl<<"student: email"<<endl<<"exist the program: exit"<<endl;
	getline(cin,idf);
	bool chk=true;
	while(chk==true){
		if(idf=="admin"){
			admin(s,b);
				
		}else if(idf=="exit"){
			chk=false;
		}else{
			bool loginchk=false;
			for(int i=0;i<10&&loginchk==false;i++){
				if(idf==s[i].getmail()){
					loginchk=true;
				}
			}
			if(loginchk==false){
				cout<<"error"<<endl<<"please login again: ";
				getline(cin,idf);
			}
		}
	}
	/*for(int i=0;i<10;i++){
		if(s[i].getid().length()!=0){
			s[i].print();			
			cout<<endl;
		}
	}*/
	//s.add();
	//s.print();
	system("pause");
	return 0;
}
void student::add(){
	string k;
	cout<<"-- add a new student --"<<endl;
	cout<<"please enter student id: ";
	//getline(cin,k);
	
}
void student::add(string a,string b,string c,string d,string e[10]){
	id=a;
	name+=b;
	depart+=c;
	email+=d;
	for(int i=0;i<10;i++){
		if(e[i].size()==0){
			break;
		}else{
			borrow[i]+=e[i];
		}
	}
}

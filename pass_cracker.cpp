#include <stdio.h>
#include <unistd.h>
#include <crypt.h>
#include<iostream>
 #include<pthread.h>
 #include <bits/stdc++.h>
 #include <stdlib.h>
 #include <vector>
#include<sys/wait.h>
#include<unistd.h>
#include "mpi.h"
#include <omp.h>
#include <string.h>
#include<time.h>
using namespace std;

//Username , saltt and SaltplusEncryptt are being passed with reference. Shadow file is read and 
// the salt and salt+Hash is stored in variable (their names are self explainatory)
bool ReadFile(char *&usernamee,char * &saltt,char *&SaltplusEncryptt)
{

	string r;  // String in which the File is being Read
	string username ; // String which stores the Username 
	
	string salt ;
	string SaltplusEncrypt;
	int dollar1 = 0;
	fstream obj;
	obj.open("shadow.txt");
	bool tru=false;

	int Counter1=0;
	int Counter2=0;
	int Counter3=0;
	int LastIndex=0;


	if (obj)
	{
		while(getline(obj,r))
		{
			for (int i=0 ; r[i]!=':' ; i++)
			{
				username+=r[i];
				
			}
			for (int i=0 ; r[i]!='\0' ; i++)
			{
				if (r[i]=='$')
				{
					for (int j=i ; r[j]!='\0' ; j++)
					{
						salt+=r[j];
						
						if (r[j]=='$')
						{
							dollar1++;
						}
						if (r[j]=='$' and dollar1==3)
						{
							LastIndex=j+1;
							tru=true;
							break;
						}
						
					}
					
				}
				if (tru==true)
				{
					break;
				}
				

			}
			SaltplusEncrypt=salt;
			for (int i=LastIndex;r[i]!=':' ; i++)
			{
				SaltplusEncrypt+=r[i];
			}
		}
		
		
			Counter1=username.length();
			Counter2=salt.length();
			Counter3=SaltplusEncrypt.length();

			
			usernamee= new char [Counter1+1];
			saltt=new char[Counter2+1];
			SaltplusEncryptt=new char [Counter3+1];

			strcpy(usernamee,username.c_str());
			strcpy(saltt,salt.c_str());
			strcpy(SaltplusEncryptt,SaltplusEncrypt.c_str());
			
		
	}
	else
	{
		cout<<"File Not Read";
	}

	
}


// Basic Function :- This function will make every possible combination of letter indexes which are being passed
//  if 3 processes are made,  1 PROCESS WILL HAVE int start = 0(a) ,  int end = 12(m)
// and 2nd process will have int start = 13 (n) and int end =25 (z) . master will get none in this case
//saltt is the SALT value from shadow and SaltplusEncyptt is salt+encrypt which is read from shadow ( to check the ending condition)
bool Func( int start , int end , char * saltt, char * SaltplusEncryptt)
{
	cout<<" "<<"Start is "<<start<<endl ;
	cout<<" "<<"End is "<<end<<endl;
	char c;

					  string comb; // contains combinations to test
					  bool x1=1;
					  bool x2=1;
					  bool x3=1;
					  bool x4=1;
					  bool x5=1;
					  bool x6=1;
					  bool x7=1;
					  bool x8=1;
					string arr1={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
					   
					   // outer loop , controls the 0th index of combination.
					for(int i=start;i<end+1;i++){
						//cout<<"i "<<i<<" "<<endl;
						if(x2==0)
						{
							c=97+(i-1);
					    	comb +=c;

					    }
					    // This loop controls 1st index of combination
					    for(int j=0;j<27;j++){
					    	//cout<<"j "<<j<<" "<<endl;
							if(x2==0)
							{
								c=97+(j-1);
						    	comb +=c;
						    }
						    //This loop  controls 2nd index of combination
							for(int k=0;k<27;k++){
								//cout<<"k "<<k<<" "<<endl;
							    	if(x2==0)
							    	{
										c=97+(k-1);
								    	comb +=c;
								    }
				 //This loop  controls 3rd index of combination

								for(int l=0;l<27;l++){
								    	if(x2==0)
								    	{
											c=97+(l-1);
									    	comb +=c;
									    }
						//This loop  controls 4th index of combination

								   for(int m=0;m<27;m++){
								    	if(x2==0)
								    	{
											c=97+(m-1);
									    	comb +=c;
									    }
						//This loop  controls 5th index of combination

									    for(int n=0;n<27;n++){
									    	if(x2==0)
									    	{
												c=97+(n-1);
										    	comb +=c;
										    }
						//This loop  controls 6th index of combination

									    	for(int o=0;o<27;o++){
									    		if(x1==0)
									    		{
													c=97+(o-1);
										    		comb +=c;
										    	}
					    		//cout<<endl<<comb<<endl<<endl;
						//This loop  controls 7th index of combination
									    		for(int p=0;p<26;p++){
									    			//cout<<"p "<<p<<endl;
									    			//char SaltplusEncryptt[]="$6$L3FTFnpd9gJHl0y8$LGJhphSZbp3uq55fe4yxov/MSCORzTpPcbczhq1LTM36IZbdZUI/yupMrLZEfhnkyY7CD8t28RVxuLIWi8mDX0";
									    			//char saltt[]="$6$L3FTFnpd9gJHl0y8$";

									    			c=97+p;
									    			//cout<<"1st"<<endl;
									    			comb +=c;
									    			cout<<comb<<endl;
									    			//cout<<"2st"<<endl;
											    	char *dec = crypt(comb.c_str() , saltt); // combination being tested
											    
											    	ifstream ob;
											    	ob.open("Password.txt"); // if password is alredy found 
											    	if (ob.is_open())
											    	{
								                    	  p=100;
								                    	  o=100;
								                    	  m=100;
								                    	  n=100;
								                    	  l=100;
								                    	  k=100;
								                    	  j=100;
								                    	  i=100;
								                    	  ob.close();
								                    }
								                     if (strcmp(SaltplusEncryptt,dec)==0) // match the decrypted string with the string (salt + encrypted)
								                      {
								                        cout<<"Password is "<<comb<<endl;
								                        ofstream obj;
								                        obj.open("Password.txt"); // if password is found , write it into a file
								                        obj<<comb;
								                        obj.close();
								                        //bool var = true;
								                        return 0;
								                        //break;
								                      }
								                      //cout<<"5st"<<endl;
											    			//cout<<comb<<" ";
									    			comb.erase(comb.size()-1);

									    			//cout<<endl<<"Loop end"<<endl;
									    			//cout<<endl<<comb<<endl<<endl;
									    		}
									    		//cout<<""<<endl;
									    		if(x1==0)
									    		{
									    			comb.erase(comb.size()-1);
									    		}
									    		x1=0;
											}
											//cout<<"*******************"<<endl;
											if(x2==0)
											{
												comb.erase(comb.size()-1);
											}
											x2=0;
										}
										//cout<<"*******************"<<endl;
										if(x3==0)
										{
											comb.erase(comb.size()-1);
										}
										x3=0;
									}
									//cout<<"*******************"<<endl;
									if(x5==0)
									{
										comb.erase(comb.size()-1);
									}
									x5=0;
								}
								//cout<<"*******************"<<endl;
								if(x6==0)
								{
									comb.erase(comb.size()-1);
								}
								x6=0;
							}
							//cout<<"*******************"<<endl;
							if(x7==0)
							{
								comb.erase(comb.size()-1);
							}
							x7=0;
						}
						//cout<<"*******************"<<endl;
						if(x8==0)
						{
							comb.erase(comb.size()-1);
						}
						x8=0;
					} 
 	
}


int main (int argc , char ** argv)
{
	//---------------------------------------------
	


	
	int length =26;
  	int rank, size, i,namelen; // mpi variables
    MPI_Status status; // mpi variables
    MPI_Init(&argc, &argv);// mpi variables
    MPI_Comm_size(MPI_COMM_WORLD, &size);// mpi variables
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);// mpi variables



  
  char Ress[26]; // Receiving Buffer
  
  //size =3 ;
    vector<string> arr1{ "a", "b", "c", "d","e","f","g","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    char arr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int divide = length/(size-1); // Equally divide the task between every process . EVERY process should get equal alphabets


    char *usernamee; // username to pass to Readfile
    char * saltt; //// uninitialized salt to pass by reference  to Readfile
    char *SaltplusEncryptt; // to pass by reference  to Readfile
    ReadFile(usernamee,saltt,SaltplusEncryptt);
    
	
	
    char ch;
    
    char **Array=new char* [size-1]; // Make 2 D array of size-1 . i.e of there are 2 process , make 2 arrays to send to 2 child processes

     for (int i=0 ; i<size-1 ; i++)
      {
        //cout<<"a"<<endl;
        Array[i] = new char  [divide];  // if processes are 5 INCLUDING MASTER and data is 20 then [ 20/4 = 5 ] 4 arrays will be made of "5" size , first array will be sent to first slave , 2nd to 2nd slave , 3rd to 3rd slave and 4th array to 4th slave
        
      }
      int k=0;
    for (int i=0 ; i<size-1 ; i++)
    {
      for (int j=0 ; j<divide ; j++)
      {
                
        Array[i][j]=arr[k]; // Shifting alphabets to the arrays
        k++;
      }
    }
   
    if (rank==0)
    {
    	// cout<<"Salt is "<<saltt<<endl<<endl;
    	// cout<<" SE is "<<SaltplusEncryptt<<endl;
     // cout<<"remaining is"<<endl;
     // for (int P=k; P<26 ; P++)
     // {	
     //   cout<<arr[P];
     // }
      int array_index=0; // determines which array to sent first .
      //int ProcSend=1;
              
      for (int i=1 ; i<size ; i++)
      {
              MPI_Send(saltt,40,MPI_CHAR,i,0,MPI_COMM_WORLD); // sends salt to every child
              MPI_Send(SaltplusEncryptt,100,MPI_CHAR,i,0,MPI_COMM_WORLD); // sends salt+encrypt to every child

        MPI_Send(Array[array_index], 26, MPI_CHAR, i, 0, MPI_COMM_WORLD); // SENDING array 1 to process 1 then incrementing index , in this way array 2 will be sent to 2nd process , 3 to 3rd process etc etc
            array_index++; 
      }
      if (k<26)
      {	
      	Func(k,26,saltt,SaltplusEncryptt); // IF ANY LETTER IS LEFT , it will find itself.
      }

    }
    if (rank!=0)
    {
        MPI_Recv(saltt,40,MPI_CHAR,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status); // child recieves SALT
        MPI_Recv(SaltplusEncryptt,100,MPI_CHAR,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status); // child recieves SALT+Encrypy
      MPI_Recv(Ress, 26, MPI_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD,&status); // this recieve receives the ALphabets in Ress array'
      printf("%s\n", Ress);

      // for (int i=0 ; i<divide ; i++)
      // {
      //   cout<<Ress[i];
      // }

      vector<string> arr2;//{ "a", "b", "c", "d","e","f","g","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
     
      string s;

      for (char a=Ress[0] ; a<=Ress[divide-1] ; a++)
      {
        s.push_back(a);
        
         arr2.push_back(s);
         s.clear();
         
      }
      //string deff = "abcdefghi";
      string arr={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      int start =0;
      int end=0;

      // This loops find the alphabet index of first letter of the Receiving array and last letter of Receiving Array
      for (int i=0 ; i<arr.length() ; i++)
      {
      	if (Ress[0]==arr[i])
      	{
      		start = i;
      	}
      	if (Ress[arr2.size()-1]==arr[i])
      	{
      		end=i;
      	}
      }
      Func(start,end,saltt,SaltplusEncryptt); // sends the first , last lettre with salt and salt + encrypt to Search
      
      //===============================================================================================================================================
   }





MPI_Finalize();
}

	//------------------------------------------


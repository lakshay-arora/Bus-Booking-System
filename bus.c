#include<stdio.h>
#include<stdlib.h>
struct travel 
{
	char name[10] ;
	int no_ticket ;
	int pin ;
	int ticket[15];
	struct travel *next ;

} *front1 = NULL ,*front2 = NULL , *front3 = NULL ; 
struct wait_list
{
	char name[10] , gender ;
	int age ;
	int pin ;
	int priority ;
}  psg1[10] , psg2[10] , psg3[10] ;

void display_bus(char a[] , int bn,int cnt,int wl) ;
void bus_chart() ;
void pass_details(char a[] ,int bus_no,int tr[][2]) ;

void queue_wail_list(int bus_no,int trans[][2],struct wait_list psg[]) ;

void cancel_ticket( char a[],int bus_no,int tr[][2]) ;
void transfer_ticket(char a[],int tr,int bus_no[][2],struct wait_list psg[]) ;
void booking(char fa[],int bus_no,int tr[][2],struct wait_list psg[],int trans[][2]) ;
void add(int sd , int trn) ;
void sub(int sd , int trn) ;
int wradd(int trn) ;
int rcadd(int trn) ;
void wadd(int sd , int trn) ;
void wsub(int sd , int trn) ;
struct travel * pointf(int bus_no) ;
int space(int tr[][2]) ;
int wspace(int tr[][2]) ;
void priArray(int a[][2]) ;
void cValues(int a[][2]) ;
int price(int bus_no,int n) ;

    int trans_1[10][2] ,trans_2[10][2] ,trans_3[10][2] ;    /*   waiting list array */
    int tic_record1[30][2] ,tic_record2[30][2] , tic_record3[30][2] ;  /*  pass array */
    char status1[30] = {".............................."} ;
    char status2[30] = {".............................."} ;
    char status3[30] = {".............................."} ;
    int count1  = 0 , count2 = 0 , count3 = 0 ;
    int wl1 = 0 , wl2 = 0 , wl3 = 0 ;
int main()
{
	int i , j ;
	int a , bk , cll ;
	char c ;

	printf("\n--------------------- WELCOME  TO  BUS BOOKING PORTAL -------------------\n");
	printf("PRESS 1 TO BOOK TICKET\nPRESS 2 TO CANCEL TICKET\nPRESS 3 TO DISPLAY TICKET AVAILABILTY\nPRESS 4 TO EXIT\n");
	while(1)
	{
		printf("\n____________");
		printf("\nENTER CHOICE : ");
	    scanf("%d,",&a);
	    printf("\n------------");
	    switch (a)
	    {
	    	case 1 :
	    	        bus_chart();
	    	        printf("\nENTER BUS  NO. TO BOOK THE TICKET : ");
	    	        scanf("%d",&bk);
	    	        if(bk == 111)
	    	        {
	    	        	display_bus(status1,bk,count1,wl1);
	    	       	    booking(status1,111,tic_record1,psg1,trans_1);
                    }
	    	        else if(bk == 222)
	    	        {
	    	        	display_bus(status2,bk,count2,wl2);
	    	        	booking(status2,222,tic_record2,psg3,trans_2);
	    	       
	    	        }
	    	        else if(bk == 333)
	    	        {
	    	        	display_bus(status3,bk,count3,wl3);
	    	        	booking(status3,333,tic_record3,psg3,trans_3);
	    	        	
	    	        }

	    	        break ;
	    	case 2 :
	    	        printf("\nENTER BUS  NO. TO CANCEL THE TICKET : ");
	    	        scanf("%d",&cll);
	    	        if(cll == 111)
	    	        {
	    	           cancel_ticket(status1,111,tic_record1);
	    	           if(wl1 > 0 )
	    	            {
	    	               transfer_ticket(status1,111,trans_1,psg1);
	    	            }
                    }
                    else if(cll == 222)
                    {
                       cancel_ticket(status2,222,tic_record2);
                       if(wl2 > 0)
                       {
	    	           transfer_ticket(status2,222,trans_2,psg2);
                       }
                    }
                    else if(cll == 333)
                    {
                       cancel_ticket(status3,333,tic_record3);
                       if(wl3 > 0)
                       {
	    	           transfer_ticket(status3,333,trans_3,psg3);
                       }
                    }
                    break ;
            case 3 :
                    bus_chart();
	    	        printf("\nENTER BUS  NO. TO CHECK AVAILABILTY : ");
	    	        scanf("%d",&bk);
	    	        if(bk == 111)
	    	        {
	    	        	display_bus(status1,bk,count1,wl1);
	    	        }
	    	        else if(bk == 222)
	    	        {
	    	        	display_bus(status2,bk,count2,wl2);
	    	        }
	    	        else if(bk == 333)
	    	        {
	    	        	display_bus(status3,bk,count3,wl3); 	
	    	        }
	    	        break ;

	    	case 4 :
	    	        exit(0);
	    	case 5 :
	    	        printf("\nWRONG CHOICE !!!!  TRY AGAIN   !!!");        


	    }
    }   


}



void display_bus(char a[],int bn,int cnt,int wl) /*   FUCTION TO DISPLAY BUS   */
{
	printf("\t\t\n                      BUS  NO   %d  BOOKING STATUS      SEATS   LEFT  : %d     WAITING LIST  :  %d            \n"  , bn , 30-cnt,wl);
	printf("\n\t\t************===********===*******===*******===*******===*******===***\n");
	printf("  \t\t* D   |       1|%c      6|%c     11|%c     16|%c     21|%c     26|%c     ||8\n",a[0],a[5],a[10],a[15],a[20],a[25]);
	printf("  \t\t*     |       2|%c      7|%c     12|%c     17|%c     22|%c     27|%c     ||8\n",a[1],a[6],a[11],a[16],a[21],a[26]);
	printf("  \t\t*             3|%c      8|%c     13|%c     18|%c     23|%c     28|%c     ||8\n",a[2],a[7],a[12],a[17],a[22],a[27]);
	printf("  \t\t*                                                                  ||8\n");
	printf("  \t\t*                                                                  ||8\n");
    printf("  \t\t*             4|%c      9|%c     14|%c     19|%c     24|%c     29|%c     ||8\n",a[3],a[8],a[13],a[18],a[23],a[28]);
	printf("  \t\t*             5|%c     10|%c     15|%c     20|%c     25|%c     30|%c     ||8\n",a[4],a[9],a[14],a[19],a[24],a[29]);
	printf("  \t\t*                                                                  ||8\n");
	printf("  \t\t****/  /****===********===*******===*******===*******===*******===***\n");
	          
}


void bus_chart()
{
	printf("\nBUS N0.     FROM          TO          PRICE PER TICKET\n");
	printf("\n111         DELHI         CHANDIGARH          Rs.  293/- \n222         DELHI         JAIPUR              Rs.  209/- \n333         DELHI         MATHURA             Rs.  312/- \n    ");
}


void pass_details(char a[] ,int bus_no,int tr[][2] )
{
	int n  , k  , sn , tn ,to[15];
	struct travel *m  , *p ;
	struct travel *front;
	front = pointf(bus_no);
	m = (struct travel *)malloc(sizeof(struct travel));
	printf("\nENTER YOUR NAME : ");
	scanf("%s",m->name);
	printf("\nENTER THE NO OF TICKETS : ");
	scanf("%d",&m->no_ticket);
	n = m->no_ticket ;
	printf("\nSET YOUR PIN NO : ");
    scanf("%d",&(m->pin));
    
	for(k = 0 ; k < n ; k++)
	{
		rb :
		printf("\nENTER SEAT NO : ");
		scanf("%d",&sn);
		if ( a[sn-1] == 'b' )
		{
			printf("\n SORRY !! SEAT IS ALREADY BOOKED !!!");
			goto rb ;
		}
		else if(a[sn-1] == '.')
		{
			tn = space(tr);
			tr[tn][0] = m->pin ;
            tr[tn][1] = sn ;
            to[k] = sn ;
            m->ticket[k] = sn ;
			a[sn-1] = 'b' ;
			printf("\nSEAT IS BOOKED ");
		}
    }
    add(n,bus_no);

    printf("\n---------------------------------------------------------------------------------------------------------------");
    printf("\n                  TICKET                                                          DATE : 19 - 10 - 2016");
    printf("\nNAME : %s                                               PIN NO : %d                                             ",m->name,m->pin);
    printf("\nSEAT NOs BOOKED : ");
    for(k = 0 ; k < n ; k++)
    {
    	printf("%d ,",to[k]);
    }
    printf("  PRICE    %d/-",price(bus_no,n));
    printf("\n---------------------------------------------------------------------------------------------------------------");
    m->next = NULL ;

    if(pointf(bus_no) == NULL)
	{
		front = m ;
	}
	else
	{
		p = pointf(bus_no) ;
		{
			while(p->next!=NULL)
			{
				p = p->next ;
			}
			p->next = m ;
		}

	}

}       
/* FUNTION FOR THE WAITING LIST WITH PRIORITY GIVEN TO SENIOR CITIZENS */
void queue_wail_list(int bus_no ,int trans[][2],struct wait_list psg[])
{	int wl ;
	wl = wspace(trans) ;
	printf("\nENTER YOUR NAME : ");
	scanf("%s",(psg[wl].name));
	printf("\nENTER YOUR AGE : ");
	scanf("%d",&(psg[wl].age));
	printf("\nSET YOUR PIN NO : ");
    scanf("%d",&(psg[wl].pin));
    trans[wl][0] = psg[wl].pin ;
    printf("\nENTER YOUR GENDER (m/f) : ");
    scanf(" %c",&psg[wl].gender);
	if(wl[psg].age  > 59  && psg[wl].gender == 'f' )
	{
		wl[psg].priority = 3 ;
        trans[wl][1] = 3 ;

		wadd(1,bus_no);
	}
	else if(wl[psg].age  > 59  && psg[wl].gender == 'm' )
	{
		wl[psg].priority = 2 ;
        trans[wl][1] = 2 ;
		wadd(1,bus_no) ;
	}
	else if(wl[psg].age  < 59 )
	{
		wl[psg].priority = 1 ;
        trans[wl][1] = 1 ;
		wadd(1,bus_no) ;
	}

}

/*  FUCTION TO CANCEL TICKET */
void cancel_ticket(char a[],int bus_no,int tr[][2])
{
	int pn ,l ,b ;
	printf("\nENTER YOUR PIN NO TO PROCEED : ");
	scanf("%d",&pn);
	for(l = 0 ; l < 30 ;l++)
	{
		if(tr[l][0] == pn)
		{
				b = tr[l][1];
				if(a[b-1] == 'b')
		        {
                    tr[l][0] = 0 ;
			        a[b-1] = '.' ;
			        sub(1,bus_no);
		        }
			
		}

	}
	printf("\nYOUR TICKETS HAS BEEN CANCELLED ");
}
/* FUCTION TO TRANFER TICKETS FROM  WAITING LIST TO CONFIRMED TICKET */
void transfer_ticket(char a[],int tr,int bus_no[][2],struct wait_list psg[])
{
	int rt  ,wt, i ,j,k,m;
    rt = rcadd(tr);
    wt = wradd(tr);
	
	
	for(i = 0 ; i <= rt ; i++)
	{
		
		for(j = 0 ; j <30 ;j++)
	    {
		    if(a[j] == '.')
		    {
		    	priArray(bus_no);
		    	k = bus_no[0][0] ;
                for(m = 0 ; m < wt ; m++)
                {
                	if(psg[m].pin == k)
                	{
                		printf("\n  %s  HAS BEEN ALLOTED SEAT NO :  %d  IN BUS NO %d",psg[m].name , (j+1), tr);
                		wsub(1,tr);
                		add(1,tr);
                		a[j] = 'b';
                		cValues(bus_no); 
                	}
                }
                
		    	
		    }
			
	    }


	}

	

	


} 
/*  FUNCTION TO CHOOOSE WHICH FUNCTION WILL WORK ON BASED OF DIFFERENT CONDITIONS */
void booking(char fa[],int bus_no,int tr[][2],struct wait_list psg[],int trans[][2])
{
	char c ;
	if( rcadd(bus_no) == 30 )
	{
		printf("\n****  SORRY !!! CURRENTLY NO SEATS ARE AVALIABLE **************");
		printf("\n****  DO YOU WANT TO ADD YOUR NAME FOR WAITING LIST (Y/N) : ");
		scanf("%c",&c);
		if (c == 'Y' || c== 'y')
		{
			queue_wail_list(bus_no,trans,psg) ;
        }
       
       
       
	}
	 else if(rcadd(bus_no) < 30 && wradd(bus_no) == 0)
	{
		pass_details(fa,bus_no,tr);

	}

	
}


void add(int sd , int trn)
{
	if(trn == 111)
	{
		count1 = count1 + sd ;
	}
	else if(trn == 222)
	{
		count2 = count2 + sd ;
	}
	else if(trn == 333)
	{
		count3 = count3 + sd ;
	}

}

int rcadd(int trn)
{
	int p ;
	if(trn == 111)
	{
		p = count1 ; 
	}
	else if(trn == 222)
	{
		p = count2 ;
	}
	else if(trn == 333)
	{
		p = count3 ;
	}
	return p ;

}
void sub(int sd , int trn)
{
	if(trn == 111)
	{
		count1 = count1 - sd ;
	}
	else if(trn == 222)
	{
		count2 = count2 - sd ;
	}
	else if(trn == 333)
	{
		count3 = count3 - sd ;
	}

}

void wadd(int sd , int trn)
{
	if(trn == 111)
	{
		wl1 = wl1 + sd ;
	}
	else if(trn == 222)
	{
		wl2 = wl2 + sd ;
	}
	else if(trn == 333)
	{
		wl3 = wl3 + sd ;
	}

}

int wradd(int trn)
{
	int x ;
	if(trn == 111)
	{
		x = wl1 ;
	}
	else if(trn == 222)
	{
		x = wl2 ;
	}
	else if(trn == 333)
	{
		x = wl3 ;
	}
	return x ;

}
void wsub(int sd , int trn)
{
	if(trn == 111)
	{
		wl1 = wl1 - sd ;
	}
	else if(trn == 222)
	{
		wl2 = wl2 - sd ;
	}
	else if(trn == 333)
	{
		wl3 = wl3 - sd ;
	}

}

struct travel * pointf(int bus_no)
{
	struct travel *t ;
	if(bus_no == 111)
	{
		t = front1 ;
	}
	else if(bus_no== 222)
	{
		t = front2 ;
	}
	else if(bus_no == 333)
	{
		t = front3 ;
	}
	return t ;

}


int space(int tr[][2])
{
	int i ;
	for(i = 0 ; i < 30 ; i++)
	{
		if(tr[i][0] == 0)
			break ;
	}
	return i ;
}

int wspace(int tr[][2])
{
	int i ;
	for(i = 0 ; i < 10 ; i++)
	{
		if(tr[i][0] == 0)
			break ;
	}
	return i ;
}

void priArray(int a[][2])
{
	int i , j ,temp ,temp1;
	int n = 10 ;
	for( i = 0 ; i < n ; i++)
	{
		for( j = 0 ; j < n ; j++)
		{
			if(a[j][1] < a[j+1][1])
			{
				temp = a[j+1][1] ;
				a[j+1][1] = a[j][1] ;
				a[j][1] = temp ;

                temp1 = a[j+1][0] ;
				a[j+1][0] = a[j][0] ;
				a[j][0] = temp1 ;

			}
		}
		n-- ;
	}
}

void cValues(int a[][2])
{
	int j ;
	int n = 10 ;
		for( j = 0 ; j < n ; j++)
		{
				a[j][1] = a[j+1][1] ;
				a[j][0] = a[j+1][0] ;
		}		
}
int price(int bus_no,int n)
{
	int i ;
	if(bus_no == 111)
	{
		i = n*293 ;
	}
	else if(bus_no == 222)
	{
		i = n*209 ;
	}
	else if(bus_no == 333)
	{
		i = n*312 ;
	}
	return i ;

}





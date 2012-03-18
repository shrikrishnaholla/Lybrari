#include "headers.h"

int leapd[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int normd[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void due_date(struct date *d)
{
	int i;
	time_t now;
	struct tm *dt;
        char dc[3],mc[3],yc[5];
        time(&now);
        dt=localtime(&now);
        strftime(dc,3,"%d",dt);
        strftime(mc,3,"%m",dt);
        strftime(yc,5,"%Y",dt);
        (d)->dd=atoi(dc);
        (d)->mm=atoi(mc);
        (d)->yy=atoi(yc);

	for(i=1;i<=15;i++)
	{
		(d)->dd++;
		if(isleap((d)->yy))
		{
			if(((d)->dd)>leapd[(d->mm)])
			{
				(d)->dd=1;
				(d)->mm++;
			}
		}
		else
		{
			if(((d)->dd)>normd[(d->mm)])
			{
				(d)->dd=1;
				(d)->mm++;
			}
		}
		if(((d)->mm)>12)
		{
			(d)->mm=1;
			(d)->yy++;
		}
	}
}

int difference(struct date d)
{
	time_t now;
        struct tm *dt;
        char dc[3],mc[3],yc[5];
	int pdd,pmm,pyy,diff=0,i=0;
        time(&now);
        dt=localtime(&now);
        strftime(dc,3,"%d",dt);
        strftime(mc,3,"%m",dt);
        strftime(yc,5,"%Y",dt);
        pdd=atoi(dc);
        pmm=atoi(mc);
        pyy=atoi(yc);
	
	while((d.dd!=pdd)&&(d.mm!=pmm)&&(d.yy!=pyy))
	{
		d.dd++;
		diff++;
                if(isleap(d.yy))
                {
                        if((d.dd)>leapd[(d.mm+1)])
                        {
                                d.dd=1;
                                d.mm++;
                        }
                }
                else
                {
                        if((d.dd)>normd[(d.mm+1)])
                        {
                                d.dd=1;
                                d.mm++;
                        }
                }
                if(d.mm>12)
                {
                        d.mm=1;
                        d.yy++;
                }
        }
	
	return diff;
}

int isleap(int y)
{
	if((((y%4)==0)&&((y%100)==0))||((y%400)==0)) return 1;
	else return 0;
}


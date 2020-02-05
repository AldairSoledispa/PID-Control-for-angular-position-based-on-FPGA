#include <stdio.h>
#include <math.h>
/*=======  niNN vector de entrada =========*/
float niNN[]={627,211,144,0,1}; //% in: 'Potenciometro','LDR1','LDR2','Dirección_t_=_0'
//% out: 'Dirección_t_+_1'
/*=======  funcion mapminmax =========*/
float *mapminmax(float input[])
{
    int i;
    float ymax=1,ymin=-1;
    float xmin[]={226,0,144,0,0};
    float xmax[]={752,979,968,1,1};
    static float output[5];				//<--------------segun el numero de entradas
    for(i=0;i<5;i++)					//<--------------segun el numero de entradas
    {
        output[i]=((ymax-ymin)/(xmax[i]-xmin[i]))*(input[i]-xmin[i])+ymin;
    }
    return output;
}
/*=======  producto punto =========*/
float DotProduct(float input1[], float input2[])
{
    int i=0;
    float acumulador=0;
    for (i=0;i!=5;i++)					//<--------------segun el numero de entradas
    {
        acumulador=input1[i]*input2[i]+acumulador;
    }
    return acumulador;
}
/*=======  tangente sigmoidal =========*/
float tansig(float input1)
{
    float tansigout=(2/(1+exp(-2*input1))-1);
    return tansigout;
}
/*=======  hidden layer =========*/
float *layer1(float *input1)
{
    float static output[10];
    float w0[]={0.39034576849028451706,-1.6987787762315802453,1.1948412292774754917,0.41521072866331326656,0.68240560458565169277};   
    float w1[]={-1.4123020983853555865,1.4987426256110449874,0.65254260453094048433,0.3987329749418426772,-0.75370793944955893906};
    float w2[]={-1.7597398636460219734,-1.9188744141296301127,0.73764017931180791976,0.55140096804031257793,0.051100186807963431102};
    float w3[]={-1.0751715123665248619,-0.45639292224193395153,-0.50202189343231806706,-0.79783250077922973631,0.5951567149861903827};
    float w4[]={0.84049460011568011275,-0.91676815959077373464,1.5488547709282558529,-0.63710114778151161197,0.54350691703179776493};
    float w5[]={0.9622020584456291159,1.7263976592880811989,0.054034186508704382113,-0.4772585951796541881,-0.53784598397612615184};
    float w6[]={1.2297379883565251468,-1.2724188387888069052,0.94673881990320940538,0.81384491823769411489,1.0939056709098724518};
    float w7[]={-1.2019921716376735787,0.50605207741466129434,1.723152122519530538,-0.10382906569809693953,-0.62111188539285822063};
	float w8[]={0.9187993683406102674,0.8869221418381033617,0.87554677913795297961,-0.96148585266335251376,-1.2361733937541348194};
	float w9[]={-0.043169660513048546679,1.0366465429919999863,-0.20218281653010805599,-1.6553876785691385987,1.0372019477636282847};
	output[0]=tansig(DotProduct(input1,w0)+(-2.2522109569932995399));
    output[1]=tansig(DotProduct(input1,w1)+(1.3818891734981806341));
    output[2]=tansig(DotProduct(input1,w2)+(1.5494734030000283376));
    output[3]=tansig(DotProduct(input1,w3)+(0.31631306902308076179));
    output[4]=tansig(DotProduct(input1,w4)+(-0.42252440548824743427));
    output[5]=tansig(DotProduct(input1,w5)+(-0.20085399667830622361));
    output[6]=tansig(DotProduct(input1,w6)+(0.47464735810361352586));
    output[7]=tansig(DotProduct(input1,w7)+(-1.185532841104793178));
    output[8]=tansig(DotProduct(input1,w8)+(1.7522675576141533149));
	output[9]=tansig(DotProduct(input1,w9)+(2.1818117251168525073));
    return output;
}
/*=======  producto punto =========*/
float DotProduct1(float input1[], float input2[])
{
    int i=0;
    float acumulador=0;
    for (i=0;i!=10;i++)									//<--------Segun el numero de neuronas en el hidden layer
    {
        acumulador=input1[i]*input2[i]+acumulador;
    }
    return acumulador;
}
/*=======  funcion mapminreverse =========*/
float mapminreverse(float input)
{
    float ymax=1,ymin=-1;
    float xmin=0;										//<--------min salida
    float xmax=1;										//<--------max salida
    static float output;
    output=((xmax-xmin)/(ymax-ymin))*(input-ymin)+xmin;
    return output;
}
/*=======  output layer =========*/
float layer2(float *input1)
{
    float static output1;
    float w0[]={0.42920318317597844215,-0.55030491222422162068,1.0660964137331330193,-0.7585793765822909096,0.74013886840374254472,1.0631041994512357984,-0.49251839711554434853,-1.0507458402349769688,-0.11199486943844902398,-0.18292189028683000784};
    output1=DotProduct1(input1,w0)+(-0.40746229839456354904);
	return mapminreverse(output1);
}
/*=======  main =========*/
int main()
{
	int n;
	float *GPP1=mapminmax(niNN);
	float input1[5];									//<--------------segun el numero de entradas
	float input2[10];									//<--------Segun el numero de neuronas en el hidden layer
	for(n=0;n<4;n++)									//<--------------segun el numero de entradas
	{
	    input1[n]=GPP1[n];
	}
	float *GPP2=layer1(input1);
	for(n=0;n<10;n++)									//<--------Segun el numero de neuronas en el hidden layer
	{
		input2[n]=GPP2[n];
	}
	float output=layer2(input2);
	printf("%f\n",output+0.35);
return 0;
}



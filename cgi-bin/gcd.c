#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *name;
  char *val;
} input_struct;

char *ReadStdin(FILE *f,char stop,int *len);
void AddToSpace(char *str);
void Convert(char *url);
char *ReadData(char *line,char stop);
int gcd(int x, int y);

main()
{
  input_struct inputs[3000];
  register int i;
  int len;
  char *remote_addr;
  
  int g, x, y;

  len = atoi(getenv("CONTENT_LENGTH")); // �������ܼ�"CONTENT_LENGTH"���o����`����
  remote_addr=getenv("REMOTE_ADDR"); 

  for (i=0;len&&(!feof(stdin));i++)
  {
    inputs[i].val=ReadStdin(stdin,'&',&len); // �Nstdin�����e�H�u&�v���}
    AddToSpace(inputs[i].val);  // �N�u+�v��^�u �v
    Convert(inputs[i].val);  // �N�Q�ন16�i�쪺�r���٭�]%�}�Y���r�^
    // �Ninputs[i].val�������W�٨��X�é��inputs[i].name���C
    inputs[i].name=ReadData(inputs[i].val,'='); 
  }
  
  printf("Content-type:text/html\n\n");
  x = atol(inputs[0].val);
  y = atol(inputs[1].val);
  g = gcd(x, y);
  printf("gcd(%d, %d) = %d<BR>", x, y, g);
  printf("lcm(%d, %d) = %d<BR>", x, y, (x*y)/g);
  
    
}

int gcd(int x, int y)
{
  // �D�̤j���]�ƪ��禡
  int r;
  while(1)
  {
    (x > y)? (r = x = x % y) : (r = y = y % x);
    if (x == 0) return y;
    if (y == 0) return x;
    if (r == 1) return 1;
  }
}

char *ReadStdin(FILE *f,char stop,int *len)
{
  int wsize;
  char *word;
  int x;
  
  wsize=102400;
  x=0;
  word=(char *) malloc(sizeof(char) * (wsize+1));
  
  while (1)
  {
    word[x]=(char)fgetc(f);
    if (x==wsize) 
    {
      word[x+1]='\0';
      wsize+=102400; 
      word=(char *)realloc(word,sizeof(char)*(wsize+1));  
    }
    --(*len);
    // �p�G�J�찱��Ÿ�(&�^�άO �o�@����stdin�����Ū���F �άO ����Ū���F�]*len==0�^
    if ((word[x] == stop)||(feof(f))||(!(*len))) 
    {
      if (word[x] != stop)
        x++;
      word[x] = '\0';
      return word;
    }
    ++x;
  }
}          


char *ReadData(char *line,char stop)
{  // �N�u���W�١v�M�u���e(value�^�v�Ϥ��}��
  int i=0,j;
  char *word=(char *) malloc(sizeof(char) * (strlen(line)+1));
  for (i=0;((line[i])&&(line[i] != stop));i++)
    word[i]=line[i];
  word[i]='\0';

  if (line[i])
    ++i;
    j=0;
    
  while (line[j++] = line[i++]);  // �Nline�������W�٧R��

  return word; // �]�Ǧ^���W�١^
}

char ConvertToHex(char *change)
{
  register char hexdigit;
  
  hexdigit=(change[0]>='A' ? ((change[0] & 0xdf)-'A')+10 : (change[0]-'0'));
  hexdigit *=16;
  hexdigit+=(change[1]>='A' ? ((change[1] & 0xdf)-'A')+10 : (change[1]-'0'));
  return(hexdigit);
}

void Convert(char *data)
{
  register int i,j;
  
  for (i=0,j=0  ;data[j];++i,++j)
  {
    if ((data[i]=data[j]) == '%')
    {
      data[i]=ConvertToHex(&data[j+1]);
      j+=2;
    }
  }
  data[i]='\0';
}

void AddToSpace(char *str)
{  // �N�u+�v�ର�u �v�]�ťա^�C
  register int i;
  
  for (i=0;str[i];i++)
    if (str[i]=='+')
      str[i] = ' ';
}            

  

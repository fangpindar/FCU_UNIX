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

  len = atoi(getenv("CONTENT_LENGTH")); // 自環境變數"CONTENT_LENGTH"取得資料總長度
  remote_addr=getenv("REMOTE_ADDR"); 

  for (i=0;len&&(!feof(stdin));i++)
  {
    inputs[i].val=ReadStdin(stdin,'&',&len); // 將stdin的內容以「&」分開
    AddToSpace(inputs[i].val);  // 將「+」轉回「 」
    Convert(inputs[i].val);  // 將被轉成16進位的字元還原（%開頭的字）
    // 將inputs[i].val中的欄位名稱取出並放到inputs[i].name中。
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
  // 求最大公因數的函式
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
    // 如果遇到停止符號(&）或是 這一次的stdin的資料讀完了 或是 完全讀完了（*len==0）
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
{  // 將「欄位名稱」和「內容(value）」區分開來
  int i=0,j;
  char *word=(char *) malloc(sizeof(char) * (strlen(line)+1));
  for (i=0;((line[i])&&(line[i] != stop));i++)
    word[i]=line[i];
  word[i]='\0';

  if (line[i])
    ++i;
    j=0;
    
  while (line[j++] = line[i++]);  // 將line中的欄位名稱刪掉

  return word; // （傳回欄位名稱）
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
{  // 將「+」轉為「 」（空白）。
  register int i;
  
  for (i=0;str[i];i++)
    if (str[i]=='+')
      str[i] = ' ';
}            

  

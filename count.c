#include <stdio.h>
#include <string.h>
#include <ctype.h> //isalpha,tolower
char txt[] = "My name is Zhou Chengyi,and you can call me Bill.I was borned in China and I speak Chinese.China,my home country,is an amazing country with a long history and a lot of traditional culture. You may  like to watch beautiful fireworks in a celebrating.However,you may not know that,fireworks comes from an small accident when alcheming long long ago in China.The home country of cute pandas is China,too.My home is in Hebei,Tangshan China.I have a big family which has four people in it.My mother is a officer worked in China Mobile.My father is a programmer.I also have a older brother,studied in a great university in China.And I,a middle school student.Well,there is more information about me,I have a lot of hobbies such as:playing basketball,drawing,and also listening to music.And I am also very glad to make new friends.I already have many friends in China,they are all very friendly however,I also need to communicate and making friends with persons that comes all over the world,including local people.Every one has their own favorite and least like.For me,I like to eat beef and noodles.They delicious and nutritious.Well, that is all the information about me.It is great to be interested about me ,about China and about Chinese culture.I want to get know about the culture all over the world welcome to communicate with me about your country.";
void count(char *txt, int tlen, int bucket[], int bucket2[tlen+1][26])
{
    for (int i = 0; i < 26; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < tlen; i++)
    {
        if (isalpha(txt[i]))
        {
            bucket[tolower(txt[i]) - 'a']++;
        }
    }
    for(int x = 0; x < tlen+1; x++)
    {
        for(int y = 0; y<26; y++)
        {
            bucket2[x][y] = 0;
        }
    }
    for (int i = 0; i < 26; i++){
        bucket2[bucket[i]][i]+= (i + 'a');
    }
}
int main()
{
    int bucket[26];
    int tlen = strlen(txt);
    int bucket2[tlen+1][26];
    count(txt, tlen, bucket, bucket2);
    /* for (int i = 0; i < 26; i++)
    {
        printf("%c:%d\n", i + 'a', bucket[i]);
    } */
    for(int x = tlen; x>=0; x--)
    {
        for(int y = 0; y<26; y++)
        {
            if(bucket2[x][y]==0)
            {
                continue;
            }
            printf("%c:%d\n",bucket2[x][y],x);
        }
    }
}
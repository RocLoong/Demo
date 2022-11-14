#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define _DATETIME_SIZE  32


// GetDate - ��ȡ��ǰϵͳ����
/**
 *  �������ƣ�GetDate
 *  ����������ȡ��ǰϵͳ����
 *
 *  ���������char * psDate  - ϵͳ���ڣ���ʽΪyyymmdd
 *  ���ؽ����0 -> �ɹ�
 */
int GetDate(char * psDate){
    time_t nSeconds;
    struct tm * pTM;
    
    time(&nSeconds); // ͬ nSeconds = time(NULL);
    pTM = localtime(&nSeconds);
    
    /* ϵͳ����,��ʽ:YYYMMDD */
    sprintf(psDate,"%04d-%02d-%02d", 
            pTM->tm_year + 1900, pTM->tm_mon + 1, pTM->tm_mday);
    
    return 0;
}

// GetTime  - ��ȡ��ǰϵͳʱ��
/**
 *  �������ƣ�GetTime
 *  ����������ȡ��ǰϵͳʱ��
 *
 *  ���������char * psTime -- ϵͳʱ�䣬��ʽΪHHMMSS
 *  ���ؽ����0 -> �ɹ�
 */
int GetTime(char * psTime) {
    time_t nSeconds;
    struct tm * pTM;
    
    time(&nSeconds);
    pTM = localtime(&nSeconds);
    
    /* ϵͳʱ�䣬��ʽ: HHMMSS */
    sprintf(psTime, "%02d:%02d:%02d",
            pTM->tm_hour, pTM->tm_min, pTM->tm_sec);
           
    return 0;       
}

// GetDateTime - ȡ��ǰϵͳ���ں�ʱ��
/**
 *  �������ƣ�GetDateTime
 *  ����������ȡ��ǰϵͳ���ں�ʱ��
 *
 *  ���������char * psDateTime -- ϵͳ����ʱ��,��ʽΪyyymmddHHMMSS
 *  ���ؽ����0 -> �ɹ�
 */
int 
GetDateTime(char * psDateTime) {
    time_t nSeconds;
    struct tm * pTM;
    
    time(&nSeconds);
    pTM = localtime(&nSeconds);

    /* ϵͳ���ں�ʱ��,��ʽ: yyyymmddHHMMSS */
    sprintf(psDateTime, "%04d-%02d-%02d %02d:%02d:%02d",
            pTM->tm_year + 1900, pTM->tm_mon + 1, pTM->tm_mday,
            pTM->tm_hour, pTM->tm_min, pTM->tm_sec);
            
    return 0;
}

// ���Դ���
int main()
{
    int ret;
    char DateTime[_DATETIME_SIZE];
    
    memset(DateTime, 0, sizeof(DateTime));
    
    /* ��ȡϵͳ��ǰ���� */
    ret = GetDate(DateTime);
    if(ret == 0) 
        printf("The Local date is %s\n", DateTime);
    else 
        perror("GetDate error!");
    
    memset(DateTime, 0, sizeof(DateTime));
    /* ��ȡ��ǰϵͳʱ�� */
    ret = GetTime(DateTime);
    if(ret == 0) 
        printf("The Local time is %s\n", DateTime);
    else 
        perror("GetTime error!");
    
    memset(DateTime, 0, sizeof(DateTime));
    /* ��ȡϵͳ��ǰ����ʱ�� */
    ret = GetDateTime(DateTime);
    if(ret == 0) 
        printf("The Local date and time is %s\n", DateTime);
    else 
        perror("GetDateTime error!");
    return 0;
}

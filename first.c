/*
* MutexTest.c
*
*  Created on: Sep 17, 2014
*      Author: NileshkumarRaghuvanshi
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t m_Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m_Mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t m_CondVar = PTHREAD_COND_INITIALIZER ;

int cond = 0;


void signaling()
{
            printf("Signal !!!\n");
            pthread_mutex_lock(&m_Mutex);
            cond = 1;
            //sleep(4);
            printf("Signalin !!!\n");

            pthread_cond_signal(&m_CondVar);
            printf("Signaled !!!\n");
            pthread_mutex_unlock(&m_Mutex);

}


void locking(int cond1, int value)
{
            printf("Locking !!\n");
                        pthread_mutex_lock(&m_Mutex);
            printf("Locked !!\n");
            if(cond1 != value)
                        pthread_cond_wait(&m_CondVar, &m_Mutex);
            printf("Unlocking !!\n");
                        pthread_mutex_unlock(&m_Mutex);
}


void *thread1(void *arg)
{
            printf("START : thread 1 !!!!\n");

                        locking(cond,1);
            printf("END : thread 1 !!!!\n");
            return NULL;
}


int main()
{
            pthread_t tid;
            printf("Parent\n");

            int status =  pthread_create(&tid,NULL,thread1,NULL);
            signaling();

            pthread_join(tid,NULL);
            printf("Parent is free to die\n");

            return 0;
}

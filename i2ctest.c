/*
*i2ctest.c
*	Raspberry Pi I2C test using wiringPi library.
*
*Copyright (c) Nahid Alam. <nahid.mahfuza.alam@gmail.com>
***********************************************************
*i2ctest is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    i2ctest is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
***********************************************************
*/

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main (int argc, char *argv[])
{
        int fd;
        int data;
        wiringPiSetup () ;
        fd=wiringPiI2CSetup (0x68) ;  /*Use i2cdetect command to find your respective device address*/
        if(fd==-1)
        {
                printf("Can't setup the I2C device\n");
                return -1;
        }
        else
        {
                for (;;)
                {
                        data=wiringPiI2CRead(fd);
                        if(data==-1)
                        {
                                printf("No data\n");
                                //return -1;
                        }
                        else
                        {
                                //print data
                                printf("data=%d\n", data);
                        }
                }
        }
        return 0;
}

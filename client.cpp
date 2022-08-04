#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "lib_netsockets/src/ftp.hh"

/////////////////////////////////////////////////////////////////////////////////////////////////////
// usage
/////////////////////////////////////////////////////////////////////////////////////////////////////

void usage()
{
    std::cout << "usage: ftp_client -s SERVER -u USER -p PASS" << std::endl;
    std::cout << "-s SERVER: fully qualified ftp server name" << std::endl;
    std::cout << "-u USER: user name" << std::endl;
    std::cout << "-p PASS: password" << std::endl;
    exit(0);
}

///////////////////////////////////////////////////////////////////////////////////////
// main
// FTP client example
///////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    const char *host_name = NULL; // server name
    const char *user_name = NULL; // user name
    const char *pass = NULL;      // password

    if (argc != 7)
    {
        usage();
    }

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 's':
                host_name = argv[i + 1];
                i++;
                break;
            case 'u':
                user_name = argv[i + 1];
                i++;
                break;
            case 'p':
                pass = argv[i + 1];
                i++;
                break;
            default:
                usage();
            }
        }
        else
        {
            usage();
        }
    }

    // client LOGIN
    ftp_t ftp(host_name, 2121);
    ftp.login(user_name, pass);

    // file sending
    ftp.send_file("prefs.txt");
    ftp.logout();

    sleep(2);

    // client LOGIN
    ftp.login(user_name, pass);

    ftp.send_file("log.txt");
    ftp.logout();

    return 0;
}

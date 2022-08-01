# Log App

## Description

The project involves having a server which receives data - logs from a client. The server will generate a directory hierarchy on-the-go according to the client's needs (different apps can all serve as clients to the server). Each directory level will be named according to the tags found in the message (priority, timestamp, etc.) The client is an app running remotely while the data is made up of logs which would help debug the code in case of run-time errors.

## Message format

The message will have a relatively intuitive form and remains unchanged for different types of logs. The format is as follows:

    tag1_value,tag2_value,tag3_value,[...],tagX_value.
    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean faucibus convallis tellus. Nulla efficitur, nunc eget tempus hendrerit, nibh felis semper dolor, ut dignissim enim magna sit amet ex.

The dot and newline are used together to separate the tag section from the log section. Theoretically speaking, the newline is not needed, as the server will know the end of the tag section is marked by the lack of a comma. However, it may improve with developing and can be removed by the developer if it's thought to not help in any way.

It should be implied that tags will not contain "," and ".". Anyways, tags will serve as folder names and therefore, it is the client's job to make sure that no invalid characters are used.

## Client auth

Each client will be associated a socket and the server will remember each client's preferences upon further connections. The communication between the client and the server will go as follows:

- the very first time a client connects to the server, it gets its own socket which will serve to identify it the next time it will connect (in case that disconnection happens). The client will send a first-time message in which it will specify the hierarchy of folders. From now on, the usual message (shown above) will respect the order of the tags that was first specified. The first-time message will look like this:

  `tag1,tag2,tag3,[...],tagX`

- in case that the client disconnects mid-transmission, there is no problem, as the communication protocol used - FTP - can resume transfers

## Protocol

The communication will implement FTP.
# FTP-log-storing-server

#include <iostream>
#include <string>

using namespace std;
bool protocolB (string protocol){
    if (protocol == "http" || protocol == "https" || protocol == "ftp" || protocol == "ftps"){
        return true;
    }
    else {
        return false;
    }
}

bool domainB (string domain){
    int j = 0;
    int i = 0;
    while (j < 2){
        if (domain[i] == '.'){
            j++;
        }
        i++;
    }

    string host = "";
    while (domain[i] != '\0'){
        host += domain[i];
        i++;
    }
    if (host == "com" || host == "net" || host == "edu" || host == "biz" || host == "gov"){
        return true;
    }
    else{
        return false;
    }
}

int convertStringToInt(string number){
    int ans = 0;
    for(unsigned int i=0; i < number.size(); i++){
            ans = ans * 10 + (int(number[i]) - 48);
    }
    return ans;
}

bool portB (string strPort){

    if (strPort == ""){
        return true;
    }
    else{
        if (strPort[0] == ':'){
        strPort.erase(strPort.begin());
        int port = convertStringToInt(strPort);
        if (port >= 1 && port <= 65535){
            return true;
        }
        else{
            return false;
        }
    }
    else {
        return false;
    }
    }
}

bool filePathB (string filePath){
    int i = 0;
    while(filePath[i] != '.'){
        i++;
    }
    string temp = "";
    while (filePath[i] != '\0'){
        temp += filePath[i];
        i++;
    }
    if (temp == ".html" || ".htm"){
        return true;
    }
    else{
        return false;
    }
}

bool parametersB (string parameters){
    if (parameters == ""){
        return true;
    }
    else{
        if (parameters[0] == '?'){
            return true;
            }
        else{
            return false;
        }
    }

}

string gethost (string domain){
    int j = 0;
    int i = 0;
    while (j < 2){
        if (domain[i] == '.'){
            j++;
        }
        i++;
    }

    string host = "";
    while (domain[i] != '\0'){
        host += domain[i];
        i++;
    }
    return host;
}

int main ()
{
    string URL;
    string protocol = "", domain = "", host = "", strPort = "", port = "", filePath = "", parameters = "", parameter = "";
    int i = 0;

    cout << "URL Name: " << endl;
    cin >> URL;

    while(URL[i] != ':'){
        protocol += URL[i];
        i++;
    }
    bool pro = protocolB(protocol);

    i += 3;
    while(URL[i] != '/' && URL[i] != ':'){
        domain += URL[i];
        i++;
    }
    bool dom = domainB(domain);

    while(URL[i] != '/'){
        strPort += URL[i];
        i++;
    }
    bool por = portB(strPort);

    while(URL[i] != '?' && URL[i] != '\0'){
        filePath += URL[i];
        i++;
    }
    bool fp = filePathB(filePath);

    while(URL[i] != '\0'){
        parameters += URL[i];
        i++;
    }
    bool para = parametersB(parameters);

    if(strPort == ""){
       strPort = "None";
    }
    else{
        strPort.erase(strPort.begin());
    }

    if(parameters == ""){
        parameters = "None";
    }
    else{
        parameters.erase(parameters.begin());
    }

    if (pro == true && dom == true && por == true && fp == true && para == true){
        cout << "Protocol: 	" << protocol << endl;
        cout << "Domain: 	" << domain << endl;
        cout << "Port:		" << strPort << endl;
        cout << "File Path:	" << filePath << endl;
        cout << "Parameters:	" << parameters << endl;
    }
    else{
            if (pro == false){
                cout << "Protocol: 	";
                cout << protocol << " is not a valid protocol." << endl;
            }
            if (dom == false){
                cout << "Domain: 	";
                cout << gethost(domain) << " is an invalid domain name." << endl;
            }
            if (por == false){
                cout << "Port:		";
                cout << "port number must be between 1 and 65535" << endl;
            }
            if (fp == false){
                cout << "File Path:	";
                cout << "File path must start with a '/' and end with .html or .htm" << endl;
            }
            if (para == false){
                cout << "Parameters:	";
                cout << "Parameter must start with a the ? character." << endl;
            }
    }
    return 0;
}

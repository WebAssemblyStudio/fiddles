#include <stdio.h>
#include <sys/uio.h>
#include <mysql.h>
#include <iostream>
using namespace std;

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  MYSQL *conn = nullptr;
  MYSQL_RES *res = nullptr;
  MYSQL_ROW row;
  string server = "localhost";
  string user = "root";
  string psw="123";
  string db= "universidad";

  conn = mysql_init(nullptr);
  bool bConnOk = mysql_real_connect(connserver.c_str(),user.c_str(), psw.c_str, db.c_str(),0,nullptr,0);
  if(!bConnOk){cout << mysql_error(conn) << endl;}
  else {
    if(mysql_query(conn,"SELECT * FROM Alumnos")){
      cout << "Error: " << mysql_error(conn) << endl;
      }else{
        res = mysql_use_result(conn);
        while((row=mysql_fech_row(res)!=nullptr)){
          cout << row[0] << " - ";
          cout << row[1] << " - ";
          cout << row[2] << " - ";
          cout << row[3] << endl;
        }
        mysql_fech_result(res);

        cout << "Conexion OK" << endl;
        mysql_close(conn);
      }
  }
  //printf("Hello World\n");
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}

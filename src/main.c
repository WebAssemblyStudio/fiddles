#include <stdio.h>
#include <sys/uio.h>
#include <windows.h>
#include <ShlObj.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
  TCHAR szPathName[MAX_PATH];
    BROWSEINFO bInfo = { 0 };
    bInfo.hwndOwner = GetForegroundWindow();//父窗口    
    bInfo.lpszTitle = TEXT("浏览文件夹");
    bInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI/*包含一个编辑框 用户可以手动填写路径 对话框可以调整大小之类的..*/ |
        BIF_UAHINT/*带TIPS提示*/ | BIF_NONEWFOLDERBUTTON /*不带新建文件夹按钮*/;
    LPITEMIDLIST lpDlist;
    //lpDlist = SHBrowseForFolder(&bInfo);
    //if (lpDlist != NULL)
    if(SHBrowseForFolder(&bInfo))
    {
        SHGetPathFromIDList(lpDlist, szPathName);
        MessageBox(NULL, szPathName, L"Dir Name", MB_OK);

    }
    else
    {
        printf("user cancle\n");
    }
    return 0;
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

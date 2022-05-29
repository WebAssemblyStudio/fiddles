#include <windows.h>
#include <memory>
#include <string>

//returns the serial number of the first physical drive in a std::string or an empty std::string in case of failure
//based on http://codexpert.ro/blog/2013/10/26/get-physical-drive-serial-number-part-1/
std::string getFirstHddSerialNumber() {
    //get a handle to the first physical drive
    HANDLE h = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if(h == INVALID_HANDLE_VALUE) return {};
    //an std::unique_ptr is used to perform cleanup automatically when returning (i.e. to avoid code duplication)
    std::unique_ptr<std::remove_pointer<HANDLE>::type, void(*)(HANDLE)> hDevice{h, [](HANDLE handle){CloseHandle(handle);}};
    //initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
    STORAGE_PROPERTY_QUERY storagePropertyQuery{};
    storagePropertyQuery.PropertyId= StorageDeviceProperty;
    storagePropertyQuery.QueryType= PropertyStandardQuery;
    //initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
    STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};
    //the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
    //call DeviceIoControl and return an empty std::string on failure
    DWORD dwBytesReturned= 0;
    if(!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
                        &storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &dwBytesReturned, NULL))
        return {};
    //allocate a suitable buffer
    const DWORD dwOutBufferSize= storageDescriptorHeader.Size;
    std::unique_ptr<BYTE[]> pOutBuffer{new BYTE[dwOutBufferSize]{}};
    //call DeviceIoControl with the allocated buffer
    if(!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
                        pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
        return {};
    //read and return the serial number out of the output buffer
    STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor= reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
    const DWORD dwSerialNumberOffset= pDeviceDescriptor->SerialNumberOffset;
    if(dwSerialNumberOffset==0) return {};
    const char* serialNumber= reinterpret_cast<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
    return serialNumber;
}

#include <iostream>
int main() {
    std::string serialNumber = getFirstHddSerialNumber();
    if(serialNumber.empty())
        std::cout << "failed to retrieve serial number\n";
    else
        std::cout << "serial number: " << serialNumber << "\n";
    return 0;
}
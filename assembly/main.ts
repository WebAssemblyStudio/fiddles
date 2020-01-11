declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function getTemporaryMobilePhoneNumber() {

  const FCClient = require('@alicloud/fc2')

  var client = new FCClient('1742088366278126', {
    accessKeyID: 'yruEXhRFGagsbNda',
    accessKeySecret: '2Bs5lPd1Yot15Ss4MB1BQR0yRmgaN9',
    region: 'cn-hangzhou'
  })

  this.phoneNumber = ''
  const serviceName = 'smsecho'
  const funcNameGetNumber = 'getNumber'

  client
    .get(
      '/proxy/smsecho/getNumber/',
      { country: this.selectedCountry.value },
      {}
    )
    .then((resp) => {
      let json = JSON.parse(resp.data)
      if (json.return_code === 0 && json.sms_read_url) {
        this.phoneNumber = json.phone_number
        this.smsReadUrl = json.sms_read_url
      } else {
        this.phoneNumber = 'error code: ' + json.return_code
        this.smsReadUrl = ''
      }
    })
    .catch((err) => {
      this.alert.alert = true
      this.alert.type = 'error'
      this.alertMessage =
        'Server response with error, please check network connection and try again!'
    })
}

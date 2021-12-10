using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace ExSerialCom

{

    public partial class Form1 : Form

    {



        private SerialPort sPort;

        private string portName = "Select Port";

        private string rxText = "";



        public Form1()

        {

            InitializeComponent();



            string[] ptNum = SerialPort.GetPortNames();



            for (int i=0; i<ptNum.Length; i++)

            {

                cmbPort.Items.Add(ptNum[i]);

            }

        }



        private void btnOpen_Click(object sender, EventArgs e)

        {

            sPort = new SerialPort();



            if(portName.Contains("Select"))

            {

                MessageBox.Show("포트를 선택해 주세요");

                return;

            }



            if(sPort.IsOpen)

            {

                MessageBox.Show("포트가 이미 열려있습니다");

                return;

            }



            sPort.PortName = portName;

            sPort.BaudRate = 9600;

            sPort.DataBits = 8;

            sPort.Parity = Parity.None;

            sPort.DataReceived += Port_DataReceived;

            //sPort.ErrorReceived += new SrialErrorReceivedEventHandler(serialPort_ErrorReceived);



            sPort.Open();

            if(sPort.IsOpen == true)

            {

                MessageBox.Show("포트 열기 성공");

            } else

            {

                MessageBox.Show("포트 열기 실패");

            }



        }



        private void btnClose_Click(object sender, EventArgs e)

        {

            if(sPort != null && sPort.IsOpen)

            {

                sPort.Close();

            }

        }



        private void btnSend_Click(object sender, EventArgs e)

        {

            if(richTextBox1.Text.Length > 0)

            {

                //포트 오픈 여부 체크

                if(sPort == null || sPort.IsOpen == false)

                {

                    MessageBox.Show("포트를 열어 주세요");

                    return;

                } else

                {

                    sPort.Write(richTextBox1.Text);

                }

            }

        }



        private void cmbPort_SelectedIndexChanged(object sender, EventArgs e)

        {

            portName = cmbPort.SelectedItem.ToString();

        }



        private void Port_DataReceived(object sender, SerialDataReceivedEventArgs e)

        {

            rxText = sPort.ReadExisting();

            this.Invoke(new EventHandler(DisplayText));

        }



        private void DisplayText(object sender, EventArgs s)

        {

            richTextBox1.Text += rxText;

        }

    }

}
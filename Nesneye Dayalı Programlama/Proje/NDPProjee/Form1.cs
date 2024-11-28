using Microsoft.VisualBasic.ApplicationServices;
using System.ComponentModel.Design.Serialization;
using System.Drawing.Text;
using System.Security.Cryptography.X509Certificates;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Tab;
using System.Drawing;

/****************************************************************************
**          SAKARYA ÜNÝVERSÝTESÝ
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**      BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**        PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
** ÖDEV NUMARASI....: 1.Proje
** ÖÐRENCÝ ADI......: Yasin Can Kaya
** ÖÐRENCÝ NUMARASI.: G221210021
** DERS GRUBU.......: 2-A
** YOUTUBE LÝNKÝ....: https://youtu.be/doIJWM3uVow
****************************************************************************/

namespace NDPProjee
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            DoubleBuffered = true;
            Text = "NDP Proje";


            Button dikdortgenButonu = new Button();
            dikdortgenButonu.Text = "Dikdörtgen - Dikdörtgen";
            dikdortgenButonu.SetBounds(0, 300, 100, 50);
            dikdortgenButonu.Click += Buton_Click;
            Controls.Add(dikdortgenButonu);

            Button cemberButonu = new Button();
            cemberButonu.Text = "Cember - Cember";
            cemberButonu.SetBounds(100, 300, 100, 50);
            cemberButonu.Click += Buton_Click1;
            Controls.Add(cemberButonu);

            Button noktaDikdortgenCarpismaButonu = new Button();
            noktaDikdortgenCarpismaButonu.Text = "Nokta - Dikdortgen";
            noktaDikdortgenCarpismaButonu.SetBounds(200, 300, 100, 50);
            noktaDikdortgenCarpismaButonu.Click += NoktaDikdortgenCarpismaButon_Click;
            Controls.Add(noktaDikdortgenCarpismaButonu);

            Button noktaCemberCarpismaButonu = new Button();
            noktaCemberCarpismaButonu.Text = "Nokta - Cember";
            noktaCemberCarpismaButonu.SetBounds(300, 300, 100, 50);
            noktaCemberCarpismaButonu.Click += NoktaCemberCarpismaButon_Click;
            Controls.Add(noktaCemberCarpismaButonu);

            Button cemberDikdortgenButonu = new Button();
            cemberDikdortgenButonu.Text = "Çember ve Dikdörtgen ";
            cemberDikdortgenButonu.SetBounds(400, 300, 100, 50);
            cemberDikdortgenButonu.Click += CemberDikdortgenButon_Click;
            Controls.Add(cemberDikdortgenButonu);

            Button carpismaButonu = new Button();
            carpismaButonu.Text = "Küre-Nokta ";
            carpismaButonu.SetBounds(500, 300, 100, 50);
            carpismaButonu.Click += CarpismaButonu_Click;
            Controls.Add(carpismaButonu);

            Button carpismaButonu2 = new Button();
            carpismaButonu2.Text = "Küre-DikdörtgenPrizma ";
            carpismaButonu2.SetBounds(600, 300, 100, 50);
            carpismaButonu2.Click += CarpismaButonu_Click2;
            Controls.Add(carpismaButonu2);

            Button noktaprizma = new Button();
            noktaprizma.Text = "Nokta-DikdörtgenPrizma ";
            noktaprizma.SetBounds(700, 300, 100, 50);
            noktaprizma.Click += CarpismaButonu_Click3;
            Controls.Add(noktaprizma);

            Button noktasilindir = new Button();
            noktasilindir.Text = "Nokta-Silindir ";
            noktasilindir.SetBounds(800, 300, 100, 50);
            noktasilindir.Click += CarpismaButonu_Click4;
            Controls.Add(noktasilindir);

            Button silindirsilindir = new Button();
            silindirsilindir.Text = "Silindir-Silindir ";
            silindirsilindir.SetBounds(900, 300, 100, 50);
            silindirsilindir.Click += CarpismaButonu_Click5;
            Controls.Add(silindirsilindir);

            Button kurekure = new Button();
            kurekure.Text = "Kure-Kure ";
            kurekure.SetBounds(1000, 300, 100, 50);
            kurekure.Click += CarpismaButonu_Click6;
            Controls.Add(kurekure);

            Button kuresilindir = new Button();
            kuresilindir.Text = "Kure-Silindir ";
            kuresilindir.SetBounds(1100, 300, 100, 50);
            kuresilindir.Click += CarpismaButonu_Click7;
            Controls.Add(kuresilindir);

            Button dpdp = new Button();
            dpdp.Text = "Prizma-Prizma ";
            dpdp.SetBounds(1200, 300, 100, 50);
            dpdp.Click += CarpismaButonu_Click8;
            Controls.Add(dpdp);


        }

        private void CarpismaButonu_Click8(object? sender, EventArgs e)
        {
            Nokta3d a = new Nokta3d(30, 80, 20);
            Nokta3d b = new Nokta3d(30, 100, 10);
            DikdortgenPrizma dp1 = new DikdortgenPrizma(a, 30, 40, 50);
            DikdortgenPrizma dp2 = new DikdortgenPrizma(b, 40, 50, 60);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                dp1.Ciz(graphics);
                dp2.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.DikdortgenPrizmaCarpisma(dp1, dp2))
                MessageBox.Show("Dikdörtgen Prizma-Dikdörtgen Prizma çarpýþmasý var.");
            else
                MessageBox.Show("Dikdörtgen Prizma-Dikdörtgen Prizma çarpýþmasý yok.");

        }

        private void CarpismaButonu_Click7(object? sender, EventArgs e)
        {
            Nokta3d a = new Nokta3d(30, 48, 20);
            Nokta3d b = new Nokta3d(30, 70, 10);
            Kure kure1 = new Kure(a, 30);
            Silindir silindir = new Silindir(b, 40, 50);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {

                kure1.Ciz(graphics);
                silindir.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.KureSilindir(kure1, silindir))
                MessageBox.Show("küre-silindir çarpýþmasý var!");
            else
                MessageBox.Show("küre-silindir çarpýþmasý yok.");
        }
        private void CarpismaButonu_Click6(object? sender, EventArgs e)
        {
            Nokta3d a = new Nokta3d(30, 48, 20);
            Nokta3d b = new Nokta3d(30, 70, 10);
            Kure kure1 = new Kure(a, 30);
            Kure kure2 = new Kure(b, 30);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {

                kure1.Ciz(graphics);
                kure2.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.KureCarpisma(kure1, kure2))
                MessageBox.Show("küre-küre çarpýþmasý var!");
            else
                MessageBox.Show("küre-küre çarpýþmasý yok.");
        }
        private void CarpismaButonu_Click5(object? sender, EventArgs e)
        {
            Nokta3d t = new Nokta3d(50, 80, 20);
            Nokta3d a = new Nokta3d(40, 90, 10);
            Silindir silindir1 = new Silindir(t, 20, 20);
            Silindir silindir = new Silindir(a, 30, 30);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                silindir1.Ciz(graphics);
                silindir.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.SilindirCarpisma(silindir1, silindir))
                MessageBox.Show("Silindir-Silindir çarpýþmasý var!");
            else
                MessageBox.Show("Silindir-Silindir çarpýþmasý yok.");
        }
        private void CarpismaButonu_Click4(object? sender, EventArgs e)
        {
            Nokta3d t = new Nokta3d(30, 100, 90);
            Nokta3d u = new Nokta3d(50, 70, 90);
            Silindir silindir1 = new Silindir(u, 30, 20);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                t.Ciz(graphics);
                silindir1.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.NoktaSilindir(t, silindir1))
                MessageBox.Show("Nokta-Silindir çarpýþmasý var!");
            else
                MessageBox.Show("Nokta-Silindir çarpýþmasý yok.");
        }
        private void CarpismaButonu_Click3(object? sender, EventArgs e)
        {
            Nokta3d r = new Nokta3d(10, 10, 30);
            Nokta3d s = new Nokta3d(30, 30, 30);
            DikdortgenPrizma dp1 = new DikdortgenPrizma(s, 20, 20, 20);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                r.Ciz(graphics);
                dp1.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.NoktaPrizma(r, dp1))
                MessageBox.Show("Nokta-Prizma çarpýþmasý var!");
            else
                MessageBox.Show("Nokta-Prizma çarpýþmasý yok.");
        }

        private void CarpismaButonu_Click2(object? sender, EventArgs e)
        {
            Nokta3d q = new Nokta3d(20, 45, 60);
            Nokta3d p = new Nokta3d(30, 45, 60);
            Kure kure2 = new Kure(p, 20);
            DikdortgenPrizma dp = new DikdortgenPrizma(q, 90, 40, 10);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                kure2.Ciz(graphics);
                dp.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.KureDikdortgenPrizma(kure2, dp))
                MessageBox.Show("Küre-Dikdörtgen Prizma çarpýþmasý var!");
            else
                MessageBox.Show("Küre-Dikdörtgen Prizma çarpýþmasý yok.");
        }

        private void CarpismaButonu_Click(object? sender, EventArgs e)
        {
            Nokta3d o = new Nokta3d(40, 50, 40);
            Nokta3d n = new Nokta3d(10, 39, 40);
            Kure kure1 = new Kure(o, 20);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                kure1.Ciz(graphics);
                n.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.NoktaKure(n, kure1))
                MessageBox.Show("Nokta-Küre çarpýþmasý var!");
            else
                MessageBox.Show("Nokta-Küre çarpýþmasý yok.");
        }

        private void CemberDikdortgenButon_Click(object? sender, EventArgs e)
        {
            Nokta k = new Nokta(75, 70);
            Nokta l = new Nokta(70, 70);
            Dikdortgen dikdortgen4 = new Dikdortgen(k, 50, 50);
            Cember cember4 = new Cember(l, 30);


            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(pictureBox.Width, pictureBox.Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                cember4.Ciz(graphics);
                dikdortgen4.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.DikdortgenCember(dikdortgen4, cember4))
                MessageBox.Show("Çember-Dikdörtgen çarpýþmasý var!");
            else
                MessageBox.Show("Çember-Dikdörtgen çarpýþmasý yok.");
        }

        private void NoktaCemberCarpismaButon_Click(object? sender, EventArgs e)
        {
            Nokta i = new Nokta(50, 70);
            Nokta j = new Nokta(80, 80);
            Cember cember3 = new Cember(j, 20);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(pictureBox.Width, pictureBox.Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                cember3.Ciz(graphics);
                i.Ciz(graphics);
            }


            pictureBox.Image = bitmap;

            if (Carpisma.NoktaCember(i, cember3))
                MessageBox.Show("Nokta-Çember çarpýþmasý var!");
            else
                MessageBox.Show("Nokta-Çember çarpýþmasý yok.");
        }
        private void NoktaDikdortgenCarpismaButon_Click(object? sender, EventArgs e)
        {
            Nokta g = new Nokta(65, 65);
            Nokta f = new Nokta(60, 60);
            Dikdortgen dikdortgen3 = new Dikdortgen(f, 20, 20);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                dikdortgen3.Ciz(graphics);
                g.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.NoktaDikdortgen(g, dikdortgen3))
                MessageBox.Show("Nokta-Dikdörtgen çarpýþmasý var!");
            else
                MessageBox.Show("Nokta-Dikdörtgen çarpýþmasý yok.");
        }
        private void Buton_Click1(object? sender, EventArgs e)
        {
            Nokta c = new Nokta(30, 30);
            Nokta d = new Nokta(160, 40);
            Cember cember1 = new Cember(c, 50);
            Cember cember2 = new Cember(d, 50);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                cember1.Ciz(graphics);
                cember2.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.CemberCarpisma(cember1, cember2))
                MessageBox.Show("Çember-Çember çarpýþmasý var!");
            else
                MessageBox.Show("Çember-Çember çarpýþmasý yok.");
        }
        private void Buton_Click(object? sender, EventArgs e)
        {
            Nokta a = new Nokta(50, 50);
            Nokta b = new Nokta(30, 20);
            Dikdortgen dikdortgen1 = new Dikdortgen(a, 20, 20);
            Dikdortgen dikdortgen2 = new Dikdortgen(b, 30, 30);

            pictureBox.Image = null;

            Bitmap bitmap = new Bitmap(Width, Height);

            using (Graphics graphics = Graphics.FromImage(bitmap))
            {
                dikdortgen1.Ciz(graphics);
                dikdortgen2.Ciz(graphics);
            }

            pictureBox.Image = bitmap;

            if (Carpisma.DikdortgenCarpisma(dikdortgen1, dikdortgen2))
                MessageBox.Show("Dikdörtgen-Dikdörtgen çarpýþmasý var!");
            else
                MessageBox.Show("Dikdörtgen-Dikdörtgen çarpýþmasý yok.");
        }






    }

    public class Nokta
    {
        public int x, y;
        public Nokta()
        {
            x = 0;
            y = 0;
        }
        public Nokta(int X, int Y)
        {
            x = X;
            y = Y;
        }

        public void Ciz(Graphics cizimAraci)
        {
            Pen pen = new Pen(Color.Black);
            cizimAraci.DrawEllipse(pen, x, y, 1, 1);
        }

        public int X { get => x; set => x = value; }
        public int Y { get => y; set => y = value; }
    }

    public class Nokta3d : Nokta
    {
        int z;
        public Nokta3d() : base() { z = 0; }

        public Nokta3d(int X, int Y, int Z) : base(X, Y)
        {
            z = Z;
        }

        public new void Ciz(Graphics cizimAraci)
        {
            Pen pen = new Pen(Color.Black);
            cizimAraci.DrawEllipse(pen, X, Y, 1, 1);
        }
        public int Z { get => z; set => z = value; }
    }

    public class Cember
    {
        Nokta m;
        int r;
        public Cember()
        {
            m = new Nokta();
            r = 0;
        }
        public Cember(Nokta M, int R)
        {
            m = M;
            r = R;
        }
        public void Ciz(Graphics cizimAraci)
        {
            int x = m.x - r;
            int y = m.y - r;
            int diameter = 2 * r;
            cizimAraci.DrawEllipse(Pens.Black, x, y, diameter, diameter);
        }

        public int R { get => r; set => r = value; }
        public Nokta M { get => m; set => m = value; }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDPProjee
{
    internal class Carpisma
    {
        public static bool DikdortgenCarpisma(Dikdortgen d1, Dikdortgen d2)
        {
            int Xa = d1.M.X + d1.En / 2;
            int Xb = d2.M.X + d2.En / 2;
            int Ya = d2.M.Y + d2.Boy / 2;
            int Yb = d2.M.Y + d2.Boy / 2;

            if (Math.Abs(Xa - Xb) < (d1.En / 2 + d2.En / 2) && Math.Abs(Ya - Yb) < (d1.Boy / 2 + d2.Boy / 2))
                return true;
            else
                return false;

        }

        public static bool CemberCarpisma(Cember c1, Cember c2)
        {
            double d = Math.Sqrt(Math.Pow(c1.M.X - c2.M.X, 2) + Math.Pow(c1.M.Y - c2.M.Y, 2));
            if (c1.R + c2.R > d)
                return true;
            else
                return false;
        }

        public static bool KureCarpisma(Kure k1, Kure k2)
        {
            double d = Math.Sqrt(Math.Pow(k1.M.X - k2.M.X, 2) + Math.Pow(k1.M.Y - k2.M.Y, 2));

            if (k1.R + k2.R > d)
                return true;
            else
                return false;
        }

        public static bool SilindirCarpisma(Silindir s1, Silindir s2)
        {
            Nokta3d pa = new Nokta3d(s1.M.X, s1.M.Y + s1.H / 2, s1.M.Z);
            Nokta3d pb = new Nokta3d(s2.M.X, s2.M.Y + s2.H / 2, s2.M.Z);

            double d = Math.Sqrt(Math.Pow((pa.X - pb.X), 2) + Math.Pow((pa.Y - pb.Y), 2) + Math.Pow((pa.Z - pb.Z), 2));

            if ((s1.R + s2.R) > d && Math.Abs(pa.Y - pb.Y) < ((s1.H + s2.H) / 2))
                return true;
            else
                return false;
        }

        public static bool NoktaDikdortgen(Nokta n,Dikdortgen d)
        {
            if (n.X >= d.M.X && n.X <= d.M.X + d.En && n.Y >= d.M.Y && n.Y<=d.M.Y+d.Boy)
                return true;
            else
                return false;
        }

        public static bool NoktaCember(Nokta n, Cember c)
        {
            double d = Math.Sqrt(Math.Pow(n.X - c.M.X, 2) + Math.Pow(n.Y - c.M.Y, 2));
            if (d < c.R)
                return true;
            else
                return false;
        }

        public static bool NoktaKure(Nokta3d n, Kure k)
        {
            double d = Math.Sqrt(Math.Pow(n.X - k.M.X, 2) + Math.Pow(n.Y - k.M.Y, 2) + Math.Pow(n.Z - k.M.Z, 2));
            if (d < k.R)
                return true;
            else
                return false;
        }

        public static bool NoktaPrizma(Nokta3d n, DikdortgenPrizma p)
        {
            if (n.X > p.M.X - p.En / 2 && n.X < p.M.X + p.En / 2 &&
                n.Y > p.M.Y - p.Boy / 2 && n.Y < p.M.Y + p.Boy / 2 &&
                n.Z > p.M.Z - p.Derinlik / 2 && n.Z < p.M.Z + p.Derinlik / 2)
                return true;
            else
                return false;
        }

        public static bool NoktaSilindir(Nokta3d n, Silindir s)
        {
            double d = Math.Sqrt(Math.Pow(n.X - s.M.X, 2) + Math.Pow(n.Z - s.M.Z, 2));
            if (d < s.R && n.Y > s.M.Y - s.H / 2 && n.Y < s.M.Y + s.H / 2)
                return true;
            else
                return false;
        }
        public static bool DikdortgenCember(Dikdortgen dikdortgen, Cember cember)
        {
            // Dikdörtgenin sol üst köşe noktasını al
            int dikdortgenSol = dikdortgen.M.X;
            int dikdortgenUst = dikdortgen.M.Y;

            // Dikdörtgenin sağ alt köşe noktasını hesapla
            int dikdortgenSag = dikdortgen.M.X + dikdortgen.En;
            int dikdortgenAlt = dikdortgen.M.Y + dikdortgen.Boy;

            // Çemberin merkez noktasını ve yarıçapını al
            int cemberMerkezX = cember.M.X;
            int cemberMerkezY = cember.M.Y;
            int cemberYaricap = cember.R;

            // Çarpışma kontrolü yap
            // Çemberin merkezi dikdörtgenin içinde mi?
            if (cemberMerkezX >= dikdortgenSol && cemberMerkezX <= dikdortgenSag &&
                cemberMerkezY >= dikdortgenUst && cemberMerkezY <= dikdortgenAlt)
            {
                return true;
            }

            // Çemberin merkezi dikdörtgenin dışında mı?
            int dikdortgenX = Math.Max(dikdortgenSol, Math.Min(cemberMerkezX, dikdortgenSag));
            int dikdortgenY = Math.Max(dikdortgenUst, Math.Min(cemberMerkezY, dikdortgenAlt));

            int dx = cemberMerkezX - dikdortgenX;
            int dy = cemberMerkezY - dikdortgenY;
            int uzaklikKare = (dx * dx) + (dy * dy);

            return uzaklikKare <= (cemberYaricap * cemberYaricap);
        }


        public static bool KureSilindir(Kure k, Silindir s)
        {

            Nokta3d altYuzeyMerkezi = new Nokta3d(s.M.X, s.M.Y - s.H / 2, s.M.Z);

            double dist = Math.Sqrt(Math.Pow(k.M.X - altYuzeyMerkezi.X, 2) + Math.Pow(k.M.Y - altYuzeyMerkezi.Y, 2) + Math.Pow(s.M.Z - altYuzeyMerkezi.Z, 2));

            if (dist < k.R + s.R && k.M.Y + k.R > s.M.Y - s.H / 2 && k.M.Y - k.R < s.M.Y + s.H / 2)
                return true;
            else
                return false;

        }

        public static bool KureDikdortgenPrizma(Kure k, DikdortgenPrizma d)
        {
            double dx = Math.Max(d.M.X - Math.Max(k.M.X, Math.Min(d.M.X, k.M.X)), 0);
            double dy = Math.Max(d.M.Y - Math.Max(k.M.Y, Math.Min(d.M.Y, k.M.Y)), 0);
            double dz = Math.Max(d.M.Z - Math.Max(k.M.Z, Math.Min(d.M.Z, k.M.Z)), 0);
            double dist = Math.Sqrt(dx * dx + dy * dy + dz * dz);

            if (dist < k.R && (Math.Abs(d.M.X - k.M.X) < d.En / 2 || Math.Abs(d.M.Y - k.M.Y) < d.Boy / 2 || Math.Abs(d.M.Z - k.M.Z) < d.Derinlik / 2))
                return true;
            else
                return false;
        }
        public static bool DikdortgenPrizmaCarpisma(DikdortgenPrizma d1, DikdortgenPrizma d2)
        {
            double dx = Math.Abs(d1.M.X - d2.M.X);
            double dy = Math.Abs(d1.M.Y - d2.M.Y);
            double dz = Math.Abs(d1.M.Z - d2.M.Z);

            if (dx < (d1.En / 2 + d2.En / 2) && dy < (d1.Boy / 2 + d2.Boy / 2) && dz < (d1.Derinlik / 2 + d2.Derinlik / 2))
                return true;
            else
                return false;
        }

    }
}

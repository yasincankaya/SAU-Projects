using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDPProjee
{
    internal class Kure
    {
        Nokta3d m;
        int r;
        public Kure() 
        {
            m=new Nokta3d();
            r = 0;
        }

        public Kure(Nokta3d M, int R)
        {
            m = M;
            r = R;
        }

        public void Ciz(Graphics cizimAraci)
        {
            int x = m.X - r;
            int y = m.Y - r;
            int diameter = 2 * r;
            cizimAraci.FillEllipse(Brushes.Red, x, y, diameter, diameter);
        }

        public Nokta3d M { get => m; set => m = value; }
        public int R { get => r; set => r = value; }
    }
}

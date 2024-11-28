using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDPProjee
{
    internal class Silindir
    {
        Nokta3d m;
        int r;
        int h;
        public Silindir()
        {
            m = new Nokta3d();
            r = 0;
            h = 0;
        }
        public Silindir(Nokta3d M, int R, int H)
        {
            m = M;
            r = R;
            h = H;
        }

        public void Ciz(Graphics cizimAraci)
        {
            int x = m.X - r;
            int y = m.Y - r;
            int width = 2 * r;
            int height = 2 * r;

            Rectangle rect = new Rectangle(x, y, width, h);
            Rectangle topEllipse = new Rectangle(x,y, width,height);
            Rectangle bottomEllipse = new Rectangle(x, y + h - height, width, height);

            cizimAraci.DrawEllipse(Pens.Black, topEllipse);
            cizimAraci.DrawEllipse(Pens.Black, bottomEllipse);
            cizimAraci.DrawRectangle(Pens.Black, rect);
        }
        public Nokta3d M { get => m; set => m = value; }
        public int R {get => r; set => r = value; }
        public int H { get => h; set => h = value;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDPProjee
{
    internal class Dikdortgen
    {
        Nokta m;
        int en;
        int boy;
        public Dikdortgen()
        {
            m=new Nokta();
            en=0;
            boy=0;
        }
        public Dikdortgen(Nokta M, int En, int Boy)
        {
            m=M;
            en=En; 
            boy=Boy;
        }
        public void Ciz(Graphics cizimAraci)
        {
            cizimAraci.DrawRectangle(Pens.Aqua, M.x, M.y, En, Boy);
        }
        public Nokta M { get => m; set => m = value; }
        public int En { get => en; set => en = value; }
        public int Boy { get => boy; set => boy = value;
        }
    }
}

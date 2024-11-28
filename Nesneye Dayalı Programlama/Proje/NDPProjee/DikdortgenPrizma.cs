using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDPProjee
{
    internal class DikdortgenPrizma
    {
        Nokta3d m;
        int en;
        int boy;
        int derinlik;

        public DikdortgenPrizma()
        {
            m = new Nokta3d();
            en = 0;
            boy = 0;
            derinlik = 0;
        }

        public DikdortgenPrizma(Nokta3d M, int En, int Boy, int Derinlik)
        {
            m = M;
            en = En;
            boy = Boy;
            derinlik = Derinlik;

        }

        public void Ciz(Graphics graphics)
        {
            int x = m.X;
            int y = m.Y;

            Point[] topFace = { new Point(x, y), new Point(x + en, y), new Point(x + en + derinlik, y - derinlik), new Point(x + derinlik, y - derinlik) };
            Point[] frontFace = { new Point(x, y), new Point(x + en, y), new Point(x + en, y + boy), new Point(x, y + boy) };
            Point[] sideFace = { new Point(x + en, y), new Point(x + en + derinlik, y - derinlik), new Point(x + en + derinlik, y + boy - derinlik), new Point(x + en, y + boy) };

            graphics.DrawPolygon(Pens.Black, topFace);
            graphics.DrawPolygon(Pens.Black, frontFace);
            graphics.DrawPolygon(Pens.Black, sideFace);

            graphics.DrawLine(Pens.Black, topFace[0], frontFace[0]);
            graphics.DrawLine(Pens.Black, topFace[1], frontFace[1]);
            graphics.DrawLine(Pens.Black, topFace[2], frontFace[2]);
            graphics.DrawLine(Pens.Black, topFace[3], frontFace[3]);
            graphics.DrawLine(Pens.Black, frontFace[0], sideFace[0]);
            graphics.DrawLine(Pens.Black, frontFace[3], sideFace[1]);
            graphics.DrawLine(Pens.Black, topFace[1], sideFace[3]);
            graphics.DrawLine(Pens.Black, topFace[2], sideFace[2]);

        }

        public Nokta3d M { get => m; set => m = value; }
        public int En { get => en; set => en = value; }
        public int Boy { get => boy; set => boy = value; }
        public int Derinlik { get => derinlik; set => derinlik = value; }
    }
}

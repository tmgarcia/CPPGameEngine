using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObjToBinaryWriter
{
    class Vec2
    {
        public float x;
        public float y;
        public override bool Equals(object obj)
        {
 	         Vec2 o = obj as Vec2;
            return Math.Abs(x-o.x)< float.Epsilon &&
                Math.Abs(y-o.y) < float.Epsilon;
        }
    }
    class Vec3
    {
        public float x;
        public float y;
        public float z;
        public override bool Equals(object obj)
        {
 	         Vec3 o = obj as Vec3;
            return Math.Abs(x-o.x)< float.Epsilon &&
                Math.Abs(y-o.y) < float.Epsilon &&
                Math.Abs(z-o.z)< float.Epsilon;
        }
    }
    class Vertex
    {
        public Vec3 position;
        public Vec2 textureCoord;
        public Vec3 normal;
        public override bool Equals(object obj)
        {
            Vertex o = obj as Vertex;
            return position.Equals(o.position) &&
                textureCoord.Equals(o.textureCoord) &&
                normal.Equals(o.normal);
        }
        public void WriteContents(BinaryWriter bw)
        {
            bw.Write(position.x);
            //Console.WriteLine("Position x " + position.x);
            bw.Write(position.y);
            //Console.WriteLine("Position y " + position.y);
            bw.Write(position.z);
            //Console.WriteLine("Position z " + position.z);
            bw.Write(normal.x);
            //Console.WriteLine("Normal x " + normal.x);
            bw.Write(normal.y);
            //Console.WriteLine("Normal y " + normal.y);
            bw.Write(normal.z);
            //Console.WriteLine("Normal z " + normal.z);
            bw.Write(textureCoord.x);
            //Console.WriteLine("UV x " + textureCoord.x);
            bw.Write(textureCoord.y);
            //Console.WriteLine("UV y " + textureCoord.y);
        }
    }
    class ObjToBinaryConverter
    {
        string inFilename = "metronome.obj";
        string outFilename = "metronome.bin";
        static List<Vertex> vertices = new List<Vertex>();
        static List<ushort> indices = new List<ushort>();

        static List<Vec3> positions = new List<Vec3>();
        static List<Vec2> textureCoords = new List<Vec2>();
        static List<Vec3> normals = new List<Vec3>();

        static void Main(string[] args)
        {
            ObjToBinaryConverter converter = new ObjToBinaryConverter();
            converter.readInObj(converter.inFilename);
            converter.WriteToBinary(converter.outFilename);
        }

        private void readInObj(string inFileName)
        {
            StreamReader input = new StreamReader(inFileName);
            input.ReadLine();
            input.ReadLine();
            //input.ReadLine();
            string line;
            while ((line = input.ReadLine()) != null)
            {
                string[] lineParts = line.Split();
                switch (lineParts[0])
                {
                    case "v":
                        addPosition(lineParts);
                        break;
                    case "vt":
                        addTextureCoord(lineParts);
                        break;
                    case "vn":
                        addNormal(lineParts);
                        break;
                    case "f":
                        MakeIndices(lineParts);
                        break;
                }
            }
        }

        private void MakeIndices(string[] lineParts)
        {
            string[] vertParts1 = lineParts[1].Split('/');
            Vertex vert1 = new Vertex
            {
                position = positions[int.Parse(vertParts1[0]) - 1],
                textureCoord = textureCoords[int.Parse(vertParts1[1]) - 1],
                normal = normals[int.Parse(vertParts1[2]) - 1],
            };
            addIndex(vert1);
            string[] vertParts2 = lineParts[2].Split('/');
            Vertex vert2 = new Vertex
            {
                position = positions[int.Parse(vertParts2[0])-1],
                textureCoord = textureCoords[int.Parse(vertParts2[1]) - 1],
                normal = normals[int.Parse(vertParts2[2])-1],
            };
            addIndex(vert2);
            string[] vertParts3 = lineParts[3].Split('/');
            Vertex vert3 = new Vertex
            {
                position = positions[int.Parse(vertParts3[0])-1],
                textureCoord = textureCoords[int.Parse(vertParts3[1]) - 1],
                normal = normals[int.Parse(vertParts3[2])-1],
            };
            addIndex(vert3);
        }
        private static void addIndex(Vertex vert)
        {
            ushort index = (ushort)vertices.IndexOf(vert);
            if (index == unchecked((ushort)-1))
            {
                vertices.Add(vert);
                index = (ushort)(vertices.Count - 1);
            }
            indices.Add(index);
        }

        private void addPosition(string[] lineParts)
        {
            Vec3 position = new Vec3
            {
                x = float.Parse(lineParts[1]),
                y = float.Parse(lineParts[2]),
                z = float.Parse(lineParts[3]),
            };
            positions.Add(position);
        }
        private void addTextureCoord(string[] lineParts)
        {
            Vec2 textureCoord = new Vec2
            {
                x = float.Parse(lineParts[1]),
                y = float.Parse(lineParts[2]),
            };
            textureCoords.Add(textureCoord);
        }
        private void addNormal(string[] lineParts)
        {
            Vec3 normal = new Vec3
            {
                x = float.Parse(lineParts[1]),
                y = float.Parse(lineParts[2]),
                z = float.Parse(lineParts[3]),
            };
            normals.Add(normal);
        }

        private void WriteToBinary(string outFileName)
        {
            BinaryWriter bw = new BinaryWriter(File.Open(outFileName, FileMode.Create));
            bw.Write(vertices.Count);
            bw.Write(indices.Count);
            int pos = 0;
            foreach (Vertex v in vertices)
            {
                v.WriteContents(bw);
            }
            foreach (ushort i in indices)
            {
                //Console.WriteLine(i);
                bw.Write(i);
            }

            bw.Close();
        }
    }
}

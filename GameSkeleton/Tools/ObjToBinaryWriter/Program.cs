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
        public Vec2(float x, float y)
        {
            this.x = x;
            this.y = y;
        }
        public Vec2()
        {
            x = 0;
            y = 0;
        }
        public override bool Equals(object obj)
        {
 	         Vec2 o = obj as Vec2;
            return Math.Abs(x-o.x)< float.Epsilon &&
                Math.Abs(y-o.y) < float.Epsilon;
        }
        public static Vec2 operator +(Vec2 v1, Vec2 v2)
        {
            return new Vec2(){ x = v1.x + v2.x, y = v1.y + v2.y};
        }
    }
    class Vec3
    {
        public float x;
        public float y;
        public float z;
        public Vec3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        public Vec3()
        {
            x = 0;
            y = 0;
            z = 0;
        }
        public Vec3 normalize()
        {
            Vec3 normalized = new Vec3();
            float length = (float)Math.Abs(Math.Sqrt(((x*x) + (y * y) + (z * z))));
            normalized.x = x / length;
            normalized.y = y / length;
            normalized.z = z / length;
            return normalized;
        }
        public override bool Equals(object obj)
        {
 	         Vec3 o = obj as Vec3;
            return Math.Abs(x-o.x)< float.Epsilon &&
                Math.Abs(y-o.y) < float.Epsilon &&
                Math.Abs(z-o.z)< float.Epsilon;
        }
        public static Vec3 operator *(Vec3 v, float f)
        {
            return new Vec3() { x = v.x * f, y = v.y * f, z = v.z * f };
        }
        public static Vec3 operator +(Vec3 v1, Vec3 v2)
        {
            return new Vec3(){ x = v1.x + v2.x, y = v1.y + v2.y, z = v1.z + v2.y};
        }
        public static Vec3 operator -(Vec3 v1, Vec3 v2)
        {
            return new Vec3() { x = v1.x - v2.x, y = v1.y - v2.y, z = v1.z - v2.y };
        }
        public static explicit operator Vec3(Vec4 v)
        {
            Vec3 vf = new Vec3(v.x, v.y, v.z);

            return vf;
        }

        public static float Dot(Vec3 v1, Vec3 v2)
        {
            return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
        }
        public static Vec3 Cross(Vec3 v1, Vec3 v2)
        {
            Vec3 vc = new Vec3();
            vc.x = v1.y * v2.z - v1.z * v2.y;
            vc.y = v1.z * v2.x - v1.x * v2.z;
            vc.z = v1.x * v2.y - v1.y * v2.x;

            return vc;
        }
    }
    class Vec4
    {
        public float x;
        public float y;
        public float z;
        public float w;
        public Vec4(float x, float y, float z, float w)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }
        public Vec4()
        {
            x = 0;
            y = 0;
            z = 0;
            w = 0;
        }
        public override bool Equals(object obj)
        {
            Vec4 o = obj as Vec4;
            return Math.Abs(x - o.x) < float.Epsilon &&
                Math.Abs(y - o.y) < float.Epsilon &&
                Math.Abs(z - o.z) < float.Epsilon &&
                Math.Abs(w - o.w) < float.Epsilon;
        }
        public static Vec4 operator +(Vec4 v1, Vec4 v2)
        {
            return new Vec4() { x = v1.x + v2.x, y = v1.y + v2.y, z = v1.z + v2.y, w = v1.w + v2.w };
        }
        public static explicit operator Vec4(Vec3 v)
        {
            Vec4 vf = new Vec4(v.x, v.y, v.z, 0);

            return vf;
        }
    }
    class Vertex
    {
        public Vec3 position;
        public Vec4 tangent;
        public Vec3 normal;
        public Vec2 textureCoord;
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
            bw.Write(position.y);
            bw.Write(position.z);
            bw.Write(tangent.x);
            bw.Write(tangent.y);
            bw.Write(tangent.z);
            bw.Write(tangent.w);
            bw.Write(normal.x);
            bw.Write(normal.y);
            bw.Write(normal.z);
            bw.Write(textureCoord.x);
            bw.Write(textureCoord.y);
        }
    }
    class ObjToBinaryConverter
    {
        static List<Vertex> vertices = new List<Vertex>();
        static List<ushort> indices = new List<ushort>();

        static List<Vec3> positions = new List<Vec3>();
        static List<Vec2> textureCoords = new List<Vec2>();
        static List<Vec3> normals = new List<Vec3>();

        static void Main(string[] args)
        {
            Console.WriteLine("Converting");
            ObjToBinaryConverter converter = new ObjToBinaryConverter();
            converter.readInObj(args[0]);
            converter.WriteToBinary(args[1]);

            //Console.WriteLine("Converting");
            //ObjToBinaryConverter converter = new ObjToBinaryConverter();
            //converter.readInObj("../../../../Resources/Models/repeatFaceUnitCube.obj");
            //converter.WriteToBinary("repeatFaceUnitCube.bin");

            Console.WriteLine("Done");
        }

        private void readInObj(string inFileName)
        {
            StreamReader input = new StreamReader(inFileName);

            //input.ReadLine();
            //input.ReadLine();
            //input.ReadLine();
            string line;
            while ((line = input.ReadLine()) != null)
            {
                //Console.WriteLine(line);
                if (!line.Contains('#') && !String.IsNullOrWhiteSpace(line))
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
            createTangents();
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

        private List<Vec3> ZeroOut(int count)
        {
            List<Vec3> list = new List<Vec3>(count);
            for (int i = 0; i < count; i++)
            {
                Vec3 v = new Vec3();
                list.Add(v);
            }

            return list;
        }

        private void createTangents()
        {
            List<Vec3> tan1 = ZeroOut(vertices.Count);
            List<Vec3> tan2 = ZeroOut(vertices.Count);
            int numTriangles = indices.Count;
            //int triangleIndex = 0;
            for (int i = 0; i < numTriangles; i+= 3)
            {
                int i1 = indices[i];
                int i2 = indices[i + 1];
                int i3 = indices[i + 2];

                Vec3 v1 = vertices[i1].position;
                Vec3 v2 = vertices[i2].position;
                Vec3 v3 = vertices[i3].position;

                Vec2 w1 = vertices[i1].textureCoord;
                Vec2 w2 = vertices[i2].textureCoord;
                Vec2 w3 = vertices[i3].textureCoord;

                float x1 = v2.x - v1.x;
                float x2 = v3.x - v1.x;
                float y1 = v2.y - v1.y;
                float y2 = v3.y - v1.y;
                float z1 = v2.z - v1.z;
                float z2 = v3.z - v1.z;

                float s1 = w2.x - w1.x;
                float s2 = w3.x - w1.x;
                float t1 = w2.y - w1.y;
                float t2 = w3.y - w1.y;

                float r = 1.0f / (s1 * t2 - s2 * t1);
                Vec3 sdir = new Vec3();
                sdir.x = (t2 * x1 - t1 * x2) * r;
                sdir.y = (t2 * y1 - t1 * y2) * r;
                sdir.z = (t2 * z1 - t1 * z2) * r;
                Vec3 tdir = new Vec3();
                tdir.x = (s1 * x2 - s2 * x1) * r;
                tdir.y = (s1 * y2 - s2 * y1) * r;
                tdir.z = (s1 * z2 - s2 * z1) * r;

                tan1[i1] += sdir;
                tan1[i2] += sdir;
                tan1[i3] += sdir;

                tan2[i1] += tdir;
                tan2[i2] += tdir;
                tan2[i3] += tdir;
            }

            for (int i = 0; i < vertices.Count; i++)
            {
                Vec3 n = vertices[i].normal;
                Vec3 t = tan1[i];
                vertices[i].tangent = (Vec4)((t - n) * Vec3.Dot(n, t)).normalize();

                vertices[i].tangent.w = (Vec3.Dot(Vec3.Cross(n, t), tan2[i]) < 0.0f) ? -1.0f : 1.0f;
            }
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

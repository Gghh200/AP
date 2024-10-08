class MVector
{
    public:
        MVector(int size);
        MVector(int size, float* input);
        ~MVector();
        void Display();
        MVector* Add(MVector* vec2);
        int GetSize();
        float* GetVectors();
        float Magnitude();
        MVector* Normalize();
    private:
        float* vectors;
        int size;
};
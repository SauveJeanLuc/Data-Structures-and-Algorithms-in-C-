template <class T> class MemoryCell{

    public:

    MemoryCell(const T & initVal = T());
    const T & read() const;
    void write(const T & x);

    private :
    T storedValue;
};
class Renderer
{
public:
    virtual void fill_rect(int x, int y, int w, int h);
    // Must be called at the end of some render loop.
    virtual void update() = 0;
};

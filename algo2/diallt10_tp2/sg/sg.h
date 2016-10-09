//  Simple Graph. A dim C graphics library based on X Window System

#ifndef SG_H
#define SG_H

extern void sg_open(unsigned int width, unsigned int height,
    unsigned long bgcolor, unsigned long fgcolor, const char *title);
extern void sg_clear(void);
extern void sg_close(void);
extern void sg_set_fgcolor(unsigned long color);
extern void sg_set_title(const char *title);

extern void sg_draw_point(int x, int y);
extern void sg_draw_line(int x1, int y1, int x2, int y2);
extern void sg_draw_rectangle(int x, int y, unsigned int width,
    unsigned int height);
extern void sg_fill_rectangle(int x, int y, unsigned int width,
    unsigned int height);

//  sg_key_event : returns nonzero (true) if and only if a key has been pressed
extern int sg_key_event(void);
//  sg_get_key : waits until a key is pressed. Then returns its lowercased value
extern int sg_get_key(void);

#define COLOR(red, green, blue)               \
    ( (((unsigned long) (blue)  & 0xff) << 0)   \
    | (((unsigned long) (green) & 0xff) << 8)   \
    | (((unsigned long) (red)   & 0xff) << 16))

#define BLACK   COLOR(  0,   0,   0)
#define RED     COLOR(255,   0,   0)
#define LIME    COLOR(  0, 255,   0)
#define BLUE    COLOR(  0,   0, 255)
#define YELLOW  COLOR(255, 255,   0)
#define CYAN    COLOR(  0, 255, 255)
#define MAGENTA COLOR(255,   0, 255)
#define WHITE   COLOR(255, 255, 255)

#endif  // SG_H

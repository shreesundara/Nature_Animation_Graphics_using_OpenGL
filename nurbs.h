#define NURB_DISPLAY_LIST 3

//int light=01;

static int showPoints = 0;

//static int year=0;
static float year=0.0f;
static int rotateAngle = 0;

static GLUnurbsObj *theNurb;

static GLfloat ctlpoints[4][4][3];

void nurb_init(void);

void nurb_idle(void);

void nurb_display(void);


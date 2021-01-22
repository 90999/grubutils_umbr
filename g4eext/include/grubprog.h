/* thank goodness gcc will place the above 8 bytes at the end of the b.out		л��л�أ�gcc������8���ֽڷ���b.out�ļ���ĩβ�������ڴ˴������κ�����asm��·�� 
 * file. Do not insert any other asm lines here.
 */
/* it seems gcc use end and/or _end for __bss_end 	�ƺ�gccʹ��end��/��end��ʾbss end */
#if 1
	#define	__BSS_END	end
#else
	#define	__BSS_END	_end
#endif

#if 1
	#define	__BSS_START	__bss_start
#elif 1
  #define	__BSS_START	edata
#else
	#define	__BSS_START	_edata
#endif

#define PROG_PSP (char*)(((int)&__BSS_END + 16) & ~0x0F)
extern int __BSS_END;
extern int __BSS_START;

unsigned long long GRUB = 0x534f443442555247LL;/* this is needed, see the following comment.  'GRUB4DOS'���Ǳ���ģ�������������� */
/* gcc treat the following as data only if a global initialization like the		gcc���ڷ��������������Ƶ�ȫ�ֳ�ʼ��ʱ�Ž�����������Ϊ���ݡ�
 * above line occurs.
 */

/* The 40-byte space is structured. 40�ֽڿռ��ǽṹ���� */
asm(".long main");		/* actually not used for now ʵ������ʱ���� */ //
asm(".long .text");		/* actually not used for now */
asm(".long etext");		/* actually not used for now */
asm(".long .data");		/* actually not used for now */
asm(".long edata");		/* actually not used for now */
asm(".long __bss_start");	/* actually not used for now */
asm(".long .bss");		/* actually not used for now */
asm(".long end");		/* this is the process end ���ǽ��̽���*/
asm(".ascii \"main_end\""); //�°汾ǩ��

/* Don't insert any code/data here! ��Ҫ����������κδ���/���ݣ�*/
/* these 16 bytes can be used for any purpose. ��16���ֽڿ��������κ�Ŀ��*/
asm(".long 0");
asm(".long 0");
asm(".long 0");
asm(".long 0");

/* Don't insert any code/data here! ��Ҫ����������κδ���/����*/

/* a valid executable file for grub4dos must end with these 8 bytes     grub4dos����Ч��ִ���ļ���������8�ֽڽ�β */
//grub4dos�ⲿ�������ǩ��
asm(".long 0x03051805");
asm(".long 0xBCBAA7BA");

asm(".globl _start");
asm("_start:");
/* thank goodness gcc will place the above 8 bytes at the end of the program		л��л�أ�gcc��������8���ֽڷ��ڳ����ļ���ĩβ�������ڴ˴������κ�����asm��·�� 
 * file. Do not insert any other asm lines here.
 */
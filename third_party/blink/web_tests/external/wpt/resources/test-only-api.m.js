/* Whether the browser is Cinaseek-based with MojoJS enabled */
export const isCinaseekBased = 'MojoInterfaceInterceptor' in self;

/* Whether the browser is WebKit-based with internal test-only API enabled */
export const isWebKitBased = !isCinaseekBased && 'internals' in self;

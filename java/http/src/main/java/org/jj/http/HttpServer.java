package org.jj.http;

import java.util.logging.Level;
import org.apache.log4j.Logger;
import org.eclipse.jetty.server.Handler;
import org.eclipse.jetty.server.Server;

/**
 *
 * @author leef
 */
public class HttpServer {

    static Logger logger = Logger.getLogger(HttpServer.class);
    private Server server;
    private int port;
    boolean isStart = false;

    public HttpServer(int port, Handler handler) {
        this.port = port;
        this.server = new Server(port);
        this.server.setHandler(handler);
    }

    public synchronized void start() throws Exception {
        if (!isStart) {
            System.out.println("start httpserver " + port);
            logger.info("start... httpserver " + port);
            try {
                server.start();
            } catch (Exception ex) {
                logger.error("httpserver start error", ex);
                throw ex;
            }

            logger.info("started httpserver " + port);
            isStart = true;
        }

//        server.join();
    }

    public synchronized void stop() throws Exception {
        if (isStart) {
            logger.info("stop httpserver " + port);
            server.stop();
            isStart = false;
        }

    }

    @Override
    protected void finalize() throws Throwable {
        server.stop();
    }
}
